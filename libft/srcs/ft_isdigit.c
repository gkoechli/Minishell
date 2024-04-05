#include "../includes/libft.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == '-')
		return (1);
	return (0);
}
