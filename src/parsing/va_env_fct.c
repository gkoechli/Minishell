#include "./include/minishell_parsing.h"

char	*get_va_env_value(char *str)
{
	t_env		*buff;

	buff = g_shell.env;
	while (buff != NULL)
	{
		if (ft_strcmp(str, buff->key) == 1)
			return (ft_strncpy(buff->value, ft_strlen(buff->value)));
		buff = buff->next;
	}
	return (NULL);
}

char	*get_va_env_key(char *str)
{
	int		i[2];
	char	*ret;

	i[0] = 0;
	i[1] = 0;
	while (str[i[0]] && str[i[0]] != ' ' && str[i[0]] != '\''
		&& str[i[0]] != '"' && str[i[0]] != '|' && str[i[0]] != '$')
		i[0]++;
	ret = malloc(sizeof(char) * (i[0] + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	while (str[i[1]] && str[i[1]] != ' ' && str[i[1]] != '\''
		&& str[i[1]] != '"' && str[i[1]] != '|'
		&& str[i[1]] != '$' && str[i[1]] != '/')
	{
		ret[i[1]] = str[i[1]];
		i[1]++;
	}
	ret[i[1]] = '\0';
	return (ret);
}

int	count_va_envl(int *count, char *str)
{
	char	*key;
	char	*value;
	int		ret;

	ret = 1;
	key = get_va_env_key(str);
	if (key == NULL)
		return (0);
	ret += ft_strlen(key) - 1;
	value = get_va_env_value(key);
	if (value == NULL)
		return (ret);
	*count += ft_strlen(value);
	return (ret);
}

char	*get_va_env(char *str)
{
	char	*key;
	char	*value;

	if (*str == '?')
		return (ft_itoa(g_shell.last_return));
	key = get_va_env_key(str);
	if (key == NULL)
		return (0);
	value = get_va_env_value(key);
	if (value == NULL)
		return (NULL);
	return (value);
}
