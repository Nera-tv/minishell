/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:50:00 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/30 12:52:37 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//TODO changer ca car tu ne doit pas afficher la variable pwd de env il faut utilise getcwd()
void	ft_pwd(t_data *data, int val)
{
	//TODO ton if est inutile fait le sur bash tu vera keur sur toi loup
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
