/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:59:07 by isneves-          #+#    #+#             */
/*   Updated: 2024/10/21 19:09:51 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_absolute_path(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0) 
			return (ft_strdup(cmd));
		else
		{
			custom_error(cmd, "command not found");
			return (NULL);
		}
	}
	return (NULL);
}

char	*find_in_path(char *cmd, char **envp)
{
	char	**envp_paths;
	char	*cmd_path;
	char	*only_path;
	int		i;

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

char	*get_path(char *cmd, char **envp)
{
	char	*path;

	path = check_absolute_path(cmd);
	if (path != NULL)
		return (path);
	return (find_in_path(cmd, envp));
}
