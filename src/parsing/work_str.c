#include "./include/minishell_parsing.h"
#define SIZE 0
#define BOL 1
#define RET_I 2

int	pass_file(char *str, int i, int balise)
{
	if (str[i + 1] == '<' || str[i + 1] == '>')
		i++;
	i++;
	while (str[i] == ' ' && i < balise)
		i++;
	while (str[i] != ' ' && i < balise)
		i++;
	return (i);
}

static int	get_work_str_size(char *str, int i, int balise)
{
	int		size;
	int		bol;

	size = 0;
	bol = 3;
	while (i < balise)
	{
		if ((str[i] == '<' || str[i] == '>') && bol == 3)
			i = pass_file(str, i, balise);
		else
		{
			if (str[i] == '\'' || str[i] == '"')
				quote_closed(str[i], &bol);
			size++;
			i++;
		}
	}
	return (size);
}

char	*set_in_out_work_str(char *str, int i, int pos)
{
	char	*ret;
	int		y;

	y = 0;
	if (str == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * ((pos - i) + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	while (str[i] && i < pos)
	{
		ret[y] = str[i];
		i++;
		y++;
	}
	ret[y] = '\0';
	return (ret);
}

char	*set_work_str(char *str, int i, int balise)
{
	char	*ret;
	int		tab[3];

	tab[BOL] = 3;
	tab[RET_I] = 0;
	tab[SIZE] = get_work_str_size(str, i, balise);
	ret = malloc(sizeof(char) * (tab[SIZE] + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	while (i < balise)
	{
		if ((str[i] == '<' || str[i] == '>') && tab[BOL] == 3)
			i = pass_file(str, i, balise);
		else
		{
			if (str[i] == '\'' || str[i] == '"')
				quote_closed(str[i], &tab[BOL]);
			ret[tab[RET_I]] = str[i];
			tab[RET_I]++;
			i++;
		}
	}
	ret[tab[RET_I]] = '\0';
	return (ret);
}
