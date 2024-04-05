#include "./include/minishell_parsing.h"

int	get_ldbl_quote(char *str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (str[i] && str[i] != '"')
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '"')
		{
			i++;
			i += count_va_envl(&ret, &str[i]);
		}
		else
		{
			i++;
			ret++;
		}
	}
	return (ret);
}

char	*set_new_ret(char *old, int size, int *i)
{
	char		*ret;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	if (old != NULL)
	{
		while (old[*i])
		{
			ret[*i] = old[*i];
			*i += 1;
		}
		ret[*i] = '\0';
	}
	return (ret);
}

void	send_new_arg(char *str, t_cmd *cmd, char *first)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			cmd->args = add_arg(&str[i], cmd, first);
			while (str[i] && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
}

char	**add_arg(char *str, t_cmd *cmd, char *first)
{
	int		y;
	int		size;
	char	**ret;

	y = 0;
	size = 0;
	while (cmd->args && cmd->args[size] != NULL)
		size++;
	ret = malloc(sizeof(char) * (size + 2));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list(ret);
	while (cmd->args && cmd->args[y] != NULL)
	{
		ret[y] = cmd->args[y];
		y++;
	}
	size = 0;
	while (str[size] && str[size] != ' ')
		size++;
	ret[y] = ft_strncpy(first, ft_strlen(first));
	ret[++y] = ft_strncpy(str, size);
	if (ret[y] != NULL)
		ret[++y] = NULL;
	return (ret);
}

int	ft_add(char *str, char *ret)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (i);
}
