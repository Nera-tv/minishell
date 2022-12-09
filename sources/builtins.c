/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:46 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 10:56:50 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	if_blt_only_arg_bis(t_data *data, int indic)
{
	if (indic == 1)
	{
		exit_if_blt_exit(data, 0);
		return (1);
	}
	else if (indic == 2)
	{
		ft_export(data, 0);
		return (1);
	}
	else if (indic == 3)
	{
		ft_unset(data, 0);
		return (1);
	}
	else if (indic == 4)
	{
		ft_cd(data, 0);
		return (1);
	}
	return (0);
}

int	if_blt_only_arg(t_data *data)
{
	if (data->cmd && data->cmd[0].cmd \
		&& ft_strnncmp(data->cmd[0].cmd, "exit", ft_strlen("exit")) == 0 \
		&& data->cmd[0].cmd[4] == '\0' && data->nbr_cmds == 1)
		return (if_blt_only_arg_bis(data, 1));
	if (data->cmd && data->cmd[0].cmd \
		&& ft_strnncmp(data->cmd[0].cmd, "export", ft_strlen("export")) == 0 \
		&& data->cmd[0].cmd[6] == '\0' && data->nbr_cmds == 1)
		return (if_blt_only_arg_bis(data, 2));
	if (data->cmd && data->cmd[0].cmd \
		&& ft_strnncmp(data->cmd[0].cmd, "unset", ft_strlen("unset")) == 0 \
		&& data->cmd[0].cmd[5] == '\0' && data->nbr_cmds == 1)
		return (if_blt_only_arg_bis(data, 3));
	if (data->cmd && data->cmd[0].cmd \
		&& ft_strnncmp(data->cmd[0].cmd, "cd", ft_strlen("cd")) == 0 \
		&& data->cmd[0].cmd[2] == '\0' && data->nbr_cmds == 1)
		return (if_blt_only_arg_bis(data, 4));
	return (0);
}

void	exec_builtins(t_data *data, int val, int blt)
{
	if (blt == 1)
		ft_echo(data, val);
	if (blt == 2)
		ft_env(data);
	if (blt == 3)
		ft_pwd(data);
	if (blt == 4)
		ft_cd(data, val);
	if (blt == 5)
		ft_export(data, val);
	if (blt == 6)
		ft_unset(data, val);
	if (blt == 7)
		return ;
}

int	is_builtins(t_data *data, int val)
{
	if (ft_strnncmp(data->cmd[val].cmd, "echo",
			ft_strlen("echo")) == 0 && data->cmd[val].cmd[4] == '\0')
		return (1);
	if (ft_strnncmp(data->cmd[val].cmd, "env",
			ft_strlen("env")) == 0 && data->cmd[val].cmd[3] == '\0')
		return (2);
	if (ft_strnncmp(data->cmd[val].cmd, "pwd",
			ft_strlen("pwd")) == 0 && data->cmd[val].cmd[3] == '\0')
		return (3);
	if (ft_strnncmp(data->cmd[val].cmd, "cd", ft_strlen("cd")) == 0
		&& data->cmd[val].cmd[2] == '\0')
		return (4);
	if (ft_strnncmp(data->cmd[val].cmd, "export", ft_strlen("export")) == 0
		&& data->cmd[val].cmd[6] == '\0')
		return (5);
	if (ft_strnncmp(data->cmd[val].cmd, "unset", ft_strlen("unset")) == 0
		&& data->cmd[val].cmd[5] == '\0')
		return (6);
	if (ft_strnncmp(data->cmd[val].cmd, "exit", ft_strlen("exit")) == 0
		&& data->cmd[val].cmd[4] == '\0')
		return (7);
	return (0);
}
