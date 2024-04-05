#include "../includes/libft.h"

static int	ft_strlen_b(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen_b(s));
	write(fd, "\n", 1);
}
