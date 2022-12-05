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
