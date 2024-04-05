#include "./include/minishell_exec.h"

char	**init_builtin_str(void)
{
	char	**ret;

	ret = malloc(sizeof(char *) * 8);
	gb_col_add_list((void *)ret);
	ret[0] = ft_strncpy("cd", 2);
	ret[1] = ft_strncpy("echo", 4);
	ret[2] = ft_strncpy("pwd", 3);
	ret[3] = ft_strncpy("export", 6);
	ret[4] = ft_strncpy("unset", 5);
	ret[5] = ft_strncpy("env", 3);
	ret[6] = ft_strncpy("exit", 4);
	ret[7] = NULL;
	return (ret);
}

int	is_builtin(char	*cmd)
{
	char	**builtin;
	int		i;

	i = 0;
	if (cmd == NULL)
		return (0);
	builtin = init_builtin_str();
	while (builtin[i] != NULL)
	{
		if (ft_strcmp(builtin[i], cmd))
			return (i + 1);
		i++;
	}
	return (0);
}
