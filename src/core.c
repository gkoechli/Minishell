#include "./includes/minishell.h"

t_g_shell		g_shell;

static void	set_return_value(void)
{
	while (g_shell.last_return > 255)
		g_shell.last_return -= 255;
}

static void	start(char **penv)
{
	g_shell.env = set_env(penv);
	g_shell.pid = 1;
	ft_signaux();
}

static void	parsing_exec(char *str)
{
	parsing(str);
	if (g_shell.error != 1)
		ft_core_exec();
	del_herdoc();
	free_gb_col();
}

int	ft_core(char **penv)
{
	char			*str;

	start(penv);
	str = readline("minishell ~ $ ");
	gb_col_add_list(str);
	while (str != NULL)
	{
		init_g_shell();
		init_gb_col();
		gb_col_add_list(str);
		if (ft_strlen(str) > 0)
			add_history(str);
		parsing_exec(str);
		g_shell.pid = 1;
		set_return_value();
		str = readline("minishell ~ $ ");
	}
	if (str != NULL)
		free(str);
	return (0);
}
