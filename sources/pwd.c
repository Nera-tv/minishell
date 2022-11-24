/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:50:00 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/24 20:48:51 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_data *data, int val)
{
	if (data->cmd[val].args && data->cmd[val].args[0][0] == '-')
	{
		ft_putstr_fd("minishell: pwd: -", 1);
		ft_putchar_fd(data->cmd[val].args[0][1], 1);
		ft_putstr_fd(": invalid option\n", 1);
		return ;
	}
	else
	{
		ft_putstr_fd(data->pwd, 1);
		ft_putchar_fd('\n', 1);
	}
}
