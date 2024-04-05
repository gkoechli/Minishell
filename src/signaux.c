#include "includes/minishell.h"

void	use_tc(void)
{
	int				fd;
	struct termios	*new;
	struct termios	*old;

	fd = ttyslot();
	new = malloc(sizeof(struct termios) * 1);
	old = malloc(sizeof(struct termios) * 1);
	if (isatty(fd))
	{
		if (tcgetattr(fd, new) == 0)
		{
			tcgetattr(fd, old);
			new->c_oflag = OPOST;
			new->c_lflag &= ~(ECHO);
			tcsetattr(fd, 0, new);
			tcsetattr(fd, 0, old);
		}
	}
	free(new);
	free(old);
}

static void	ft_handler_bis(void)
{
	write(1, "\b\b  \b\b", 6);
	if (g_shell.in_herdoc == 1 && g_shell.pid == 0)
		exit(130);
	use_tc();
}

static void	ft_handler(int nb)
{
	if (nb == SIGINT)
	{
		write(1, "\b\b  \b\b", 6);
		if (g_shell.pid != 0)
		{
			g_shell.error = 1;
			if (g_shell.in_herdoc != 1 && g_shell.pid == 1)
			{
				write(1, "\n", 1);
				rl_on_new_line();
				rl_replace_line("", 0);
				rl_redisplay();
			}
		}
		else
			exit(130);
	}
	else if (nb == SIGQUIT)
		ft_handler_bis();
}

void	ft_signaux(void)
{
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, ft_handler);
}
