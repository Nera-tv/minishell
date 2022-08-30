/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_var_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:59 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/31 00:40:24 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	args_var_env(t_data *data, int val)
{
	int	arg_count;
	int	i;

	arg_count = 0;
	while (data->cmd[val].args[arg_count]
		!= NULL && nb_args(data->cmd[val].args) >= 1)
	{
		i = 0;
		while (data->cmd[val].args[arg_count][i] != '\0')
		{
			if (data->cmd[val].args[arg_count][i] == '\\')
				i = if_back_slash(data, val, arg_count);
			else if (data->cmd[val].args[arg_count][i] == '\'')
				i = i + 1;
			else if (data->cmd[val].args[arg_count][i] == '\"')
				i = i + 1;
			else
				i = i + 1;
		}
		arg_count++;
	}
}
