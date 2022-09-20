/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_var_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:59 by dvilard           #+#    #+#             */
/*   Updated: 2022/09/01 12:51:09 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	args_var_env(t_data *data, int val)
{
	int	arg_count;

	arg_count = 0;
	while (data->cmd[val].args[arg_count]
		!= NULL && nb_args(data->cmd[val].args) >= 1)
	{
		arg_count++;
	}
}
