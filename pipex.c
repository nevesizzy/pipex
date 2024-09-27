/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:51:37 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/27 20:05:02 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	envp_check(char **envp)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) && envp[i][6])
			check = 1;
		i++;
	}
	if (!check)
	{
		custom_error("Error", "There are no values ​​in the path environment.");
		exit(EXIT_FAILURE);
	}	
}
void	child_process(int *fd, char **argv, char **envp)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
		exit_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	if (dup2(fd[1], STDOUT_FILENO) == -1 || dup2(fd_in, STDIN_FILENO) == -1)
    		exit_error();
	close(fd[0]);
	run_cmd(argv[2], envp);
}

void	father_process(int *fd, char **argv, char **envp)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		exit_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[1]);
	run_cmd(argv[3], envp);
	close(fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		custom_error("pipex:", "wrong number of arguments or bad arguments");
		custom_error("Usage:", "./pipex <file1> <cmd1> <cmd2> <file2>");
		exit(EXIT_FAILURE);
	}
	envp_check(envp);
	if (pipe(fd) == -1)
		exit_error();
	pid = fork();
	if (pid == -1)
		exit_error();
	if (pid == 0)
	{
		close(fd[0]);
		child_process(fd, argv, envp);
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	father_process(fd, argv, envp);
	close(fd[0]);
	return (EXIT_SUCCESS);
}
// valgrind --leak-check=full --trace-children=yes
