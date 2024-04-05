#include "./includes/gb_collector.h"

void	gb_col_add_list(void *ptr)
{
	t_gb_col	*list;
	t_gb_col	*current;

	if (g_shell.list == NULL)
		return ;
	current = g_shell.list;
	while (current->next != NULL)
		current = current->next;
	if (current->ptr == NULL)
		current->ptr = ptr;
	else
	{
		list = malloc(sizeof(t_gb_col) * 1);
		list->ptr = ptr;
		current->next = list;
		current = list;
		current->next = NULL;
	}
}

void	free_gb_col(void)
{
	t_gb_col	*buff;

	buff = g_shell.list;
	while (buff != NULL)
	{
		if (buff->ptr != NULL)
			free(buff->ptr);
		buff = g_shell.list->next;
		free(g_shell.list);
		g_shell.list = buff;
	}
}
