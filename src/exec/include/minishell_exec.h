#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H
# include "../../includes/minishell.h"

int		is_builtin(char	*cmd);
void	ft_core_exec(void);
char	**get_env_tab(void);
void	ft_pipe(int fd, char **env, char *cmd);
char	*set_cmd_path(t_cmd *cmd, char **path);
#endif
