#include "../includes/minishell.h"

void	built_env(t_cmd *cmds)
{
	t_env	*buff;

	buff = g_shell.env;
	while (buff != NULL)
	{
		if (buff->no_value == 0)
		{
			write(cmds->fd_out, buff->key, ft_strlen(buff->key));
			write(cmds->fd_out, "=", 1);
			write(cmds->fd_out, buff->value, ft_strlen(buff->value));
			write(cmds->fd_out, "\n", 1);
		}
		buff = buff->next;
	}
	if (g_shell.env != NULL)
		g_shell.last_return = 0;
}
