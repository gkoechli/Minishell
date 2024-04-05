#include "./include/minishell_exec.h"

char	*set_str_path(char *path, t_cmd *cmd)
{
	char	*ret;
	char	*buff;

	buff = ft_strjoin(path, "/");
	ret = ft_strjoin(buff, cmd->cmd);
	return (ret);
}

char	*set_cmd_path(t_cmd *cmd, char **path)
{
	char	*cmd_path;
	int		i;

	i = 0;
	if (cmd == NULL || cmd->cmd == NULL || cmd->cmd[0] == '\0')
		return (NULL);
	if (path == NULL)
	{
		ft_error(cmd->cmd, "No such file or directory\n", 127);
		return (NULL);
	}
	if (access(cmd->cmd, F_OK) != -1)
		return (cmd->cmd);
	cmd_path = set_str_path(path[i], cmd);
	while (access(cmd_path, F_OK) == -1 && path[++i] != NULL)
		cmd_path = set_str_path(path[i], cmd);
	if (path[i] == NULL)
	{
		ft_error(cmd->cmd, "Command not found\n", 127);
		return (cmd->cmd);
	}
	return (cmd_path);
}
