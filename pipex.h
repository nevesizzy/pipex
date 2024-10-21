/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:51:53 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/27 20:05:37 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include "LIBFT/libft.h"

void	custom_error(char *header, char *msg);
void	exit_error(void);
void	ft_free(char **str);
char	*get_path(char *cmd, char **env);
char  *check_absolute_path(char *cmd);
char  *find_in_path(char *cmd, char **envp);
void	run_cmd(char *cmd, char **envp);
void	envp_check(char **envp);

void	child_process(int *fd, char **argv, char **envp);
void	father_process(int *fd, char **argv, char **envp);

#endif
