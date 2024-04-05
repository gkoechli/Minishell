#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	int		len;

	len = count * size;
	ret = malloc(len);
	gb_col_add_list((void *)ret);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, len);
	return (ret);
}
