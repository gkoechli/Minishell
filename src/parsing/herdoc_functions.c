#include "./include/minishell_parsing.h"

void	del_herdoc(void)
{
	t_cmd	*cmds;

	cmds = g_shell.cmds;
	while (cmds != NULL)
	{
		if (cmds->fd_in != 0)
			close(cmds->fd_in);
		if (cmds->fd_out != 1)
			close(cmds->fd_out);
		if (cmds->herdoc_file != NULL)
			unlink(cmds->herdoc_file);
		cmds = cmds->next;
	}
}

char	*find_correct_name(int count)
{
	char	*buff;
	char	*str;
	char	*ret;

	str = ".herdocfile_";
	buff = ft_itoa(count);
	ret = ft_strjoin(str, buff);
	return (ret);
}

int	create_herdoc_fd(t_cmd *cmd)
{
	int		ret;
	char	*file;
	int		i;

	i = 0;
	file = find_correct_name(i);
	while (access(file, F_OK) != -1 && i < 2147483647)
		file = find_correct_name(++i);
	if (i == 2147483647)
		ft_error("minishell", "herdoc error, impossible to create\n", 1);
	if (g_shell.error == 0)
		ret = open(file, O_CREAT | O_WRONLY);
	else
		return (-1);
	cmd->herdoc_file = file;
	return (ret);
}

char	*reajust_prompt(char *str, t_cmd *cmd)
{
	char	*ret;

	ret = NULL;
	if (cmd->herdoc_extend == 1)
	{
		ret = ft_strjoin(str, "\n");
		return (ret);
	}
	while (*str != '\0')
	{
		if (*str == '$')
		{
			str++;
			ret = ft_add_var_env(ret, &str);
		}
		else
			ret = ft_add_char(ret, &str);
	}
	ret = ft_strjoin(ret, "\n");
	return (ret);
}

int	parse_herdoc(char **str, t_cmd *cmd)
{
	int		fd;
	char	*del;
	char	*prompt;

	prompt = NULL;
	del = NULL;
	fd = create_herdoc_fd(cmd);
	*str += 1;
	while (**str == ' ' && **str)
		*str += 1;
	if (**str == '\0')
		return (ft_error("minishell", "heredoc need a delimiter\n", 1));
	del = set_herdoc_del(cmd, str);
	parse_herdoc_bis(cmd, fd, del, prompt);
	close(fd);
	fd = open(cmd->herdoc_file, O_RDONLY);
	return (fd);
}
