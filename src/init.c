#include "./includes/minishell.h"

void	init_g_shell(void)
{
	g_shell.cmds = NULL;
	g_shell.pid = 1;
	g_shell.in_herdoc = 0;
	g_shell.error = 0;
}

t_cmd	*init_cmd(t_cmd	*cmd)
{
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	cmd->herdoc_extend = 0;
	cmd->herdoc_file = NULL;
	return (cmd);
}

void	init_gb_col(void)
{
	g_shell.list = malloc(sizeof(t_gb_col));
	g_shell.list->ptr = NULL;
	g_shell.list->next = NULL;
}
