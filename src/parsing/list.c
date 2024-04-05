#include "./include/minishell_parsing.h"

t_cmd	*ft_add_list(t_cmd *start)
{
	t_cmd	*buff;
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	gb_col_add_list((void *)new);
	if (start != NULL)
	{
		buff = start->next;
		while (buff != NULL)
		{
			start = start->next;
			buff = start->next;
		}
		start->next = new;
	}
	else
		g_shell.cmds = new;
	new->next = NULL;
	new = init_cmd(new);
	return (new);
}

t_cmd	*get_last_elem(void)
{
	t_cmd	*buff;

	buff = g_shell.cmds;
	if (buff != NULL)
		while (buff->next != NULL)
			buff = buff->next;
	return (buff);
}
