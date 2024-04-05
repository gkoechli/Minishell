#include "./include/minishell_parsing.h"

void	parse_herdoc_bis(t_cmd *cmd, int fd, char *del, char *prompt)
{
	if (del != NULL)
	{
		g_shell.in_herdoc = 1;
		g_shell.pid = fork();
	}
	else
		return ;
	if (g_shell.pid == 0)
	{
		prompt = readline("> ");
		while (ft_strcmp(prompt, del) != 1
			&& prompt != NULL && g_shell.error != 1)
		{
			prompt = reajust_prompt(prompt, cmd);
			ft_putstr_fd(prompt, fd);
			if (g_shell.error != 1)
				prompt = readline("> ");
		}
		exit(0);
	}
	else
	{
		wait(&g_shell.last_return);
		g_shell.in_herdoc = 0;
	}
}
