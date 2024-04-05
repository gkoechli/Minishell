#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ret;

	ret = (unsigned char *)s;
	while (*ret)
		ret++;
	if (*ret == c)
		return ((char *)ret);
	while (ret != (unsigned char *)s)
	{
		if (*ret == c)
			return ((char *)ret);
		ret--;
	}
	if (*ret == c)
		return ((char *)ret);
	return (NULL);
}
