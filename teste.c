#include "pipex.h"

void	custom_error(char *header, char *msg)
{
	ft_putstr_fd(header, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	exit_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*get_path(char *cmd, char **envp)
{
	char	**envp_paths;
	char	*cmd_path;
	int		i;
	char	*only_path;

	i = 0;
	// Verifica se "PATH" está no envp
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
	{
		custom_error(cmd, "PATH not found in environment");
		return (NULL);
	}
	envp_paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (envp_paths[++i])
	{
		only_path = ft_strjoin(envp_paths[i], "/");
		cmd_path = ft_strjoin(only_path, cmd);
		free (only_path);
		// Verifica se o caminho do comando é válido
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			ft_free(envp_paths);
			return (cmd_path);
		}
		free(cmd_path);
	}
	ft_free(envp_paths);
	custom_error(cmd, "command not found");
	return (NULL);
}

void	run_cmd(char *cmd, char **envp)
{
	char	**cmd_and_flags;
	char	*path;

	cmd_and_flags = ft_split(cmd, ' ');
	path = get_path(cmd_and_flags[0], envp);
	if (!path)
	{
		ft_free(cmd_and_flags);
		exit(127); // Código de retorno para "command not found"
	}
	// Executa o comando
	if (execve(path, cmd_and_flags, envp) == -1)
	{
		ft_free(cmd_and_flags);
		free (path);
		exit_error(); // Erro ao tentar executar o comando
	}
}

void	child_process(int *fd, char **argv, char **envp)
{
	int	fd_in;

	// Abrir arquivo de entrada para leitura
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		exit_error();
	// Redirecionar saída do pipe para a saída padrão (stdout)
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit_error();
	// Redirecionar entrada do arquivo para a entrada padrão (stdin)
	if (dup2(fd_in, STDIN_FILENO) == -1)
		exit_error();
	// Fechar descritores desnecessários
	close(fd[0]);
	close(fd[1]);
	close(fd_in);
	run_cmd(argv[2], envp); // Executa o comando 1
}

void	father_process(int *fd, char **argv, char **envp)
{
	int	fd_out;

	// Abrir arquivo de saída para escrita
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		exit_error();
	// Redirecionar entrada do pipe para a entrada padrão (stdin)
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit_error();
	// Redirecionar saída do arquivo para a saída padrão (stdout)
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		exit_error();
	// Fechar descritores desnecessários
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	run_cmd(argv[3], envp); // Executa o comando 2
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	// Verifica o número de argumentos
	if (argc != 5)
	{
		custom_error("Error", "Wrong number of arguments");
		custom_error("Usage", "./pipex <file1> <cmd1> <cmd2> <file2>");
		exit(EXIT_FAILURE);
	}
	// Cria o pipe
	if (pipe(fd) == -1)
		exit_error();
	// Cria o processo filho
	pid = fork();
	if (pid == -1)
		exit_error();
	if (pid == 0)
		child_process(fd, argv, envp); // Processo filho
	close(fd[1]); // Fechar o lado de escrita do pipe no processo pai
	waitpid(pid, NULL, 0); // Espera o processo filho terminar
	father_process(fd, argv, envp); // Processo pai
	close(fd[0]); // Fechar o lado de leitura do pipe no processo pai
	return (EXIT_SUCCESS);
}
