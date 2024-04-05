#include "./include/minishell_parsing.h"

int	get_size(char *str, char del)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != del && str[i])
		i++;
	return (i);
}
