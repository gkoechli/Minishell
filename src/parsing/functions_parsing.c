#include "./include/minishell_parsing.h"
#define INDEX  0
#define BOL  1
#define EMPTY  2

int	get_next_pipe(char *str)
{
	int		tab[3];

	tab[INDEX] = -1;
	tab[BOL] = 3;
	tab[EMPTY] = 0;
	while (str[++tab[INDEX]])
	{
		if (str[tab[INDEX]] != ' ')
			tab[EMPTY] = 1;
		if (str[tab[INDEX]] == '"' && tab[BOL] > 2)
			tab[BOL] = 1;
		else if (str[tab[INDEX]] == '\'' && tab[BOL] > 2)
			tab[BOL] = 2;
		else if (str[tab[INDEX]] == '"' && tab[BOL] == 1)
			tab[BOL] = 3;
		else if (str[tab[INDEX]] == '\'' && tab[BOL] == 2)
			tab[BOL] = 3;
		else if (tab[BOL] > 2 && str[tab[INDEX]] == '|')
			break ;
	}
	if ((tab[BOL] == 3 && (str[tab[INDEX]] == '\0'
				|| str[tab[INDEX] + 1] != '|')) && tab[EMPTY] == 1)
		return (tab[INDEX]);
	ft_error("minishell", "syntax error \n", 2);
	return (tab[INDEX]);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 && s2)
	{
		while (*s1 && *s2)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
	}
	return (0);
}

int	ft_error(char *prog, char *msg, int nb)
{
	write(2, prog, ft_strlen(prog));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	g_shell.error = 1;
	g_shell.last_return = nb;
	return (-1);
}

char	*ft_create(int size)
{
	char	*ret;

	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	return (ret);
}

int	quote_closed(char c, int *bol)
{
	if (c == '\'' && *bol == 3)
		*bol = 1;
	else if (c == '\'' && *bol == 1)
		*bol = 3;
	else if (c == '"' && *bol == 3)
		*bol = 2;
	else if (c == '"' && *bol == 2)
		*bol = 3;
	return (1);
}
