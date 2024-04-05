#include "../includes/libft.h"

static size_t	ft_strlen_b(const char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strchr_b(const char *s, int c)
{
	char			*ret;

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

static char	*ft_substr_b(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	max_size;

	max_size = ft_strlen_b(s);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	while (i < len && s[i] && start < max_size)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	x;
	unsigned int	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	x = 0;
	while (s1[x] && ft_strchr_b(set, s1[x]) != NULL)
		x++;
	len = ft_strlen_b(&s1[x]);
	if (len != 0)
		while (s1[x + len - 1] && ft_strchr_b(set, s1[x + len - 1]) != NULL)
			len--;
	return (ft_substr_b(s1, x, len));
}
