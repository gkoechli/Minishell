#include "../includes/minishell.h"

static void	flag_ok(t_cmd *cmds, int *y)
{
	if (cmds->args == NULL || cmds->args[1] == NULL)
		return ;
	while (cmds->args[*y] != NULL)
	{
		write(cmds->fd_out, cmds->args[*y], ft_strlen(cmds->args[*y]));
		*y += 1;
		if (cmds->args[*y] != NULL)
			write(cmds->fd_out, " ", 1);
	}
}

static void	flag_not_ok(t_cmd *cmds, int *y)
{
	if (cmds->args == NULL)
		return ;
	while (cmds->args[*y] != NULL)
	{
		write(cmds->fd_out, cmds->args[*y], ft_strlen(cmds->args[*y]));
		*y += 1;
		if (cmds->args[*y] != NULL)
			write(cmds->fd_out, " ", 1);
	}
	write(cmds->fd_out, "\n", 1);
}

static void	set_mod(int *mod, int *y, t_cmd *cmds)
{
	int	i;

	i = 1;
	if (cmds->args[1] == NULL)
		return ;
	while (cmds->args[*y])
	{	
		if (cmds->args[*y][0] == '-' && cmds->args[*y][i] == 'n')
		{
			while (cmds->args[*y][i] == 'n')
				i++;
			if (cmds->args[*y][i] == '\0')
			{	
				*mod = 1;
				*y += 1;
			}
			else
				break ;
		}
		else
			break ;
		i = 1;
	}
}

void	built_echo(t_cmd *cmds)
{
	int		y;
	int		mod;

	y = 1;
	mod = 0;
	set_mod(&mod, &y, cmds);
	if (mod == 1)
		flag_ok(cmds, &y);
	else
		flag_not_ok(cmds, &y);
	g_shell.last_return = 0;
}
