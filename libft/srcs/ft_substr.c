#include "../includes/libft.h"

static size_t	ft_strlen_b(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	max_size;

	i = 0;
	if (!s)
		return (NULL);
	max_size = ft_strlen_b(s);
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
