#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (*ret)
	{
		if ((unsigned char)*ret == c)
			return (ret);
		ret++;
	}
	if (*ret == c)
		return (ret);
	return (NULL);
}
