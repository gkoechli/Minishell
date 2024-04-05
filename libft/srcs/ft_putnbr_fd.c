#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_bis;
	char			c;

	if (n < 0)
	{
		n_bis = -n;
		write(fd, "-", 1);
	}
	else
		n_bis = n;
	if (n_bis > 9)
		ft_putnbr_fd((n_bis / 10), fd);
	c = (n_bis % 10) + '0';
	write(fd, &c, 1);
}
