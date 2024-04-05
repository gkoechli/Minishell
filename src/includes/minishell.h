#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <signal.h>
# include <termio.h>
# include "./struct.h"
# include "../../libft/includes/libft.h"
# include "../exec/include/minishell_exec.h"

# include <readline/readline.h>
# include <readline/history.h>

extern t_g_shell		g_shell;

// Functions
int			ft_error(char *prog, char *msg, int nb);
int			ft_strcmp(char *s1, char *s2);

// Chained list
t_cmd		*ft_add_list(t_cmd *start);
t_cmd		*get_last_elem(void);

// Core
int			ft_core(char **penv);
void		deffine_cmd_sep(char *str, int i, int pos, t_cmd *cmd);
void		parsing(char *str);

// Env
char		*set_key_env(char *str);
char		*set_value_env(char *str);
t_env		*set_env(char **penv);
char		*get_va_env_value(char *str);
char		*get_va_env_key(char *str);
char		*get_va_env(char *str);
int			count_va_envl(int *count, char *str);

// Init
void		init_g_shell(void);
t_cmd		*init_cmd(t_cmd	*cmd);
void		reinit_g_shell(void);
void		init_gb_col(void);

// builtin
void		built_cd(t_cmd *cmds);
void		built_echo(t_cmd *cmds);
void		built_pwd(t_cmd *cmds);
void		built_env(t_cmd *cmds);
void		built_exit(t_cmd *cmds);
void		built_unset(t_cmd *cmds);
void		built_export(t_cmd *cmds);

// +
void		ft_test(void);
void		del_herdoc(void);
void		free_env(void);

void		ft_signaux(void);

#endif
