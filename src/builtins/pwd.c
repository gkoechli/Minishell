#include "../includes/minishell.h"

void	built_pwd(t_cmd *cmds)
{
	char	*str;

	str = getcwd(NULL, 0);
	write(cmds->fd_out, str, ft_strlen(str));
	write(cmds->fd_out, "\n", 1);
	free (str);
}
