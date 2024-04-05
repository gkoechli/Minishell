#include "../includes/libft.h"

static size_t	ft_strlen_b(const char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			size;
	char		*ret;

	i = 0;
	size = ft_strlen_b(s1) + ft_strlen_b(s2);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	while (s1 != NULL && *s1)
	{
		ret[i++] = *s1;
		s1++;
	}
	while (s2 != NULL && *s2)
	{
		ret[i++] = *s2;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}
