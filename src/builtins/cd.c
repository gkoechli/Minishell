#include "../includes/minishell.h"

static char	*ft_str_duplicate(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_update_pwd(void)
{
	t_env	*old;
	t_env	*new;

	old = g_shell.env;
	new = g_shell.env;
	while (old != NULL && ft_strcmp(old->key, "OLDPWD") == 0)
		old = old->next;
	while (new != NULL && ft_strcmp(new->key, "PWD") == 0)
		new = new->next;
	if (old != NULL && old->value != NULL)
		free(old->value);
	if (new != NULL && old != NULL)
		old->value = ft_str_duplicate(new->value);
	if (new != NULL)
		free(new->value);
	new->value = getcwd(NULL, 0);
}

void	built_cd(t_cmd *cmds)
{
	if (cmds->args[1] == NULL)
	{
		if (chdir(get_va_env_value("HOME")) != -1)
		{
			if (g_shell.pid != 0)
				ft_update_pwd();
			g_shell.last_return = 0;
		}
		else
			ft_error("minishell", "HOME not set\n", 1);
	}
	else if (cmds->args[2] != NULL)
		ft_error("minishell", " cd: Wrong number of argument\n", 1);
	else if (chdir(cmds->args[1]) != -1)
	{
		if (g_shell.pid != 0)
			ft_update_pwd();
		g_shell.last_return = 0;
	}
	else
		ft_error("minishell", "wrong use of cd: Need a directory\n", 1);
}
