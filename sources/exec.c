/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:45:53 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/12 10:42:38 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	save_output(t_data *data, int val)
{
	if (val != 0)
	{
		if (close(data->pipein[0]) < 0
			|| close(data->pipein[1]) < 0)
			ft_exit(ERRFD, data, 2);
	}
	data->pipein[0] = data->pipeout[0];
	data->pipein[1] = data->pipeout[1];
	return (0);
}

void	ft_stat_check_bis(t_data *data, int val, char *msg)
{
	ft_printf(2, "minishell: %s: %s\n", data->cmd[val].cmd, msg);
	data->err_nbr = 126;
}

int	ft_stat_check(t_data *data, int val, char *str)
{
	char	*cmd;

	cmd = data->cmd[val].cmd;
	if (cmd == NULL)
		return (-1);
	if (cmd == '\0')
		return (1);
	if (str == NULL)
		stat(cmd, &data->stat);
	else
		stat(str, &data->stat);
	if (S_ISDIR(data->stat.st_mode) && str != NULL)
	{
		ft_stat_check_bis(data, val, "is a directory");
		return (2);
	}
	else if (S_ISREG(data->stat.st_mode))
		return (0);
	return (0);
}

char	**built_env(t_data *data, t_list_env *env)
{
	int		i;
	char	**envp;

	i = 0;
	envp = malloc(sizeof(char *) * data->nb_env);
	if (!envp)
		ft_exit(ERRMEMALLOC, data, 2);
	while (i < data->nb_env)
	{
		envp[i] = ft_strjoin(env[i].name, "=");
		envp[i] = ft_strjoin(envp[i], env[i].content);
		i++;
	}
	return (envp);
}

int	ft_exec(t_data *data, int val)
{
	if (ft_stat_check(data, val, data->cmd[val].cmd_path[0]) == 0)
	{
		execve(data->cmd[val].cmd_path[0], data->cmd[val].cmd_path, \
			built_env(data, data->env));
		ft_printf(2, "minishell: %s: %s\n", data->cmd[val].cmd, \
			strerror(errno));
		ft_exit(NULL, data, 2);
	}
	return (0);
}
