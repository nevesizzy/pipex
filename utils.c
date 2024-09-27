/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:51:45 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/27 19:51:39 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	envp_paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (envp_paths[++i])
	{
		only_path = ft_strjoin(envp_paths[i], "/");
		cmd_path = ft_strjoin(only_path, cmd);
		free(only_path);
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
	if (cmd_and_flags == NULL || cmd_and_flags[0] == NULL)
	{
		custom_error("run_cmd:", "command not found or invalid");
		exit(EXIT_FAILURE);
	}
	path = get_path(cmd_and_flags[0], envp);
	if (!path)
	{
		ft_free(cmd_and_flags);
		free(path);
		exit(127);
	}
	if (execve(path, cmd_and_flags, envp) == -1)
	{
		ft_free(cmd_and_flags);
		free(path);
		exit_error();
	}
}
