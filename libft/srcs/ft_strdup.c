#include "../includes/libft.h"

static size_t	ft_strlen_b(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char		*ret;
	int			i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen_b(s1) + 1));
	gb_col_add_list((void *)ret);
	if (ret == NULL)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
