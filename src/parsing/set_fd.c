#include "include/minishell_parsing.h"

int	set_fd_in(char **str)
{
	int		ret;
	char	*file;

	file = get_cmd_fd(str);
	ret = open(file, O_RDONLY);
	if (ret < 0)
	{
		perror(file);
		g_shell.error = 1;
	}
	return (ret);
}

int	set_fd_out(char **str, int mod)
{
	char	*file;
	int		ret;

	file = get_cmd_fd(str);
	if (mod == 0)
		ret = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
				| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	else
		ret = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR
				| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (ret < 0)
	{
		perror(file);
		g_shell.error = 1;
	}
	return (ret);
}
