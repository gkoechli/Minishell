#include "../includes/minishell.h"

void	built_unset(t_cmd *cmds)
{
	t_env	*buff;
	t_env	*tmp;
	int		i;

	i = 0;
	if (cmds == NULL || cmds->args[1] == NULL || g_shell.env == NULL)
		return ;
	buff = g_shell.env;
	tmp = buff;
	while (buff != NULL)
	{
		if (ft_strcmp(buff->key, cmds->args[1]))
		{
			if (i != 0)
				tmp->next = buff->next;
			else
				g_shell.env = buff->next;
			free(buff);
			break ;
		}
		tmp = buff;
		buff = buff->next;
		i++;
	}
}
