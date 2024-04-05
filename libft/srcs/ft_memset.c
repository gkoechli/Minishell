#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int		i;

	i = -1;
	if (n > 0)
	{
		*((unsigned char *)s) = c;
		while (++i < n)
			*((unsigned char *)s + i) = c;
	}
	return (s);
}
