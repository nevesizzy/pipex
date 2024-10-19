// tentativa de path absoluta

char *get_path(char *cmd, char **envp)
{
    char **envp_paths;
    char *cmd_path;
    int i;
    char *only_path;

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