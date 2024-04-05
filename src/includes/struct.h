#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_gb_col
{
	void			*ptr;
	struct s_gb_col	*next;
}	t_gb_col;

// Structure pour les variables environement
typedef struct s_env
{
	char			*key;
	char			*value;
	int				no_value;
	struct s_env	*next;
}	t_env;

// Structure des commandes
typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	int				fd_in;
	int				fd_out;
	char			*herdoc_file;
	int				herdoc_extend;
	struct s_cmd	*next;
}	t_cmd;

// structure global
typedef struct s_g_shell
{
	t_env			*env;
	char			**builtins;
	t_cmd			*cmds;
	int				last_return;
	int				error;
	int				in_herdoc;
	t_gb_col		*list;
	int				pid;
}	t_g_shell;

#endif