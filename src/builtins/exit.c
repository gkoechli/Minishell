#include "../includes/minishell.h"

void	free_env(void)
{
	t_env		*env;
	t_env		*tmp;

	env = g_shell.env;
	tmp = env->next;
	free(env->key);
	free(env->value);
	free(env);
	while (tmp != NULL)
	{
		env = tmp;
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
	}
}

void	built_exit(t_cmd *cmds)
{
	int		i;

	i = 0;
	if (cmds->args[1] != NULL)
	{
		while (cmds->args[1][i] && g_shell.error != 1)
			if (!ft_isdigit(cmds->args[1][i++]))
				ft_error(cmds->args[1], "numeric argument required\n", 2);
		if (cmds->args[1][i] == '\0')
			g_shell.last_return = ft_atoi(cmds->args[1]);
	}
	else
		g_shell.last_return = 0;
	if (cmds->args[1] != NULL && cmds->args[2] != NULL)
		ft_error("minishell", "too many arguments", 2);
	free_gb_col();
	free_env();
	write(1, "exit\n", 5);
	exit(g_shell.last_return);
}
