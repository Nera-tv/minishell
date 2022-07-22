/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:46 by dvilard           #+#    #+#             */
/*   Updated: 2022/07/22 13:43:11 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    exec_builtins(t_data *data, int val)
{
    ft_echo(data, val);
}

int		is_builtins(t_data *data, int val)
{
	if (ft_strnncmp(data->cmd[val].cmd, "echo", ft_strlen("echo")) == 0)
		return (1);
	return (0);
}