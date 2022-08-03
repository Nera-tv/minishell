/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neress <neress@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:46 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/03 07:49:59 by neress           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    exec_builtins(t_data *data, int val, int blt)
{
	if (blt == 1)
    	ft_echo(data, val);
	if (blt == 2)
		ft_env(data);
	if (blt == 3)
		ft_pwd(data);
}

int		is_builtins(t_data *data, int val)
{
	if (ft_strnncmp(data->cmd[val].cmd, "echo", ft_strlen("echo")) == 0)
		return (1);
	if (ft_strnncmp(data->cmd[val].cmd, "env", ft_strlen("env")) == 0)
		return (2);
	if (ft_strnncmp(data->cmd[val].cmd, "pwd", ft_strlen("pwd")) == 0)
		return (3);
	return (0);
}