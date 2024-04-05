#include "./include/minishell_exec.h"

void	ft_putstr_in(char *ret, char *s1)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		*ret = s1[i];
		i++;
		ret++;
	}
	*ret = '\0';
}

char	*ft_strjoinc(char *s1, char *s2, char c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	gb_col_add_list((void *)ret);
	if (s1)
		ft_putstr_in(ret, s1);
	if (c)
	{
		i = ft_strlen(ret);
		ret[i] = c;
		i++;
	}
	if (s2)
		ft_putstr_in(&ret[i], s2);
	i = ft_strlen(ret);
	return (ret);
}

char	**get_env_tab(void)
{
	t_env	*buff;
	char	**ret;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	buff = g_shell.env;
	while (buff != NULL)
	{
		i[0]++;
		buff = buff->next;
	}
	ret = malloc(sizeof(char *) * (i[0] + 1));
	gb_col_add_list((void *)ret);
	buff = g_shell.env;
	while (buff != NULL)
	{
		ret[i[1]] = ft_strjoinc(buff->key, buff->value, '=');
		i[1]++;
		buff = buff->next;
	}
	ret[i[1]] = NULL;
	return (ret);
}
