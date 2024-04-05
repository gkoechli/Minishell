#include "../includes/libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char	*dst_buffer;
	unsigned char	*src_buffer;

	dst_buffer = ((unsigned char *)str1);
	src_buffer = ((unsigned char *)str2);
	if (n > 0)
	{
		*dst_buffer = *src_buffer;
		dst_buffer++;
		src_buffer++;
		n--;
	}
	while (n > 0 && *(src_buffer - 1) != (unsigned char)c)
	{
		*dst_buffer = *src_buffer;
		dst_buffer++;
		src_buffer++;
		n--;
	}
	if (n == 0 && *(src_buffer - 1) != (unsigned char)c)
		return (NULL);
	return (dst_buffer);
}
