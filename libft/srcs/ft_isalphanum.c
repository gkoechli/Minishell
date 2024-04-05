#include "../includes/libft.h"

int	ft_isalphanum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && ft_isalpha(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
