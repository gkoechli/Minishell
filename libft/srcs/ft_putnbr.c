#include "../includes/libft.h"

void	ft_putnbr(int nb, int base)
{
	char	*base_set;
	int		i;

	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		nb = -nb;
	}
	i = nb % base;
	base_set = "0123456789abcdef";
	if (nb / base > 0)
		ft_putnbr(nb / base, base);
	ft_putchar(base_set[i]);
}
