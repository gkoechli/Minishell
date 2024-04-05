#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_buff;
	unsigned char	*src_buff;
	int				i;

	dst_buff = ((unsigned char *)dst);
	src_buff = ((unsigned char *)src);
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		dst_buff[i] = src_buff[i];
		i++;
		n--;
	}
	return (dst_buff);
}
