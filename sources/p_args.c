/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:28:43 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:12:53 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_var_args(t_data *data, int val)
{
	data->cmd[val]._args = NULL;
	data->cmd[val].args = NULL;
	data->cmd[val].args_len = NULL;
}

int	get_arg_line_len(t_data *data, int val, int i)
{
	while (data->cmd[val]._cmd[i] != '\0')
		i++;
	return (i);
}

void	ft_arg_cpy(t_data *data, int val, int i)
{
	int	j;

	j = 0;
	while (data->cmd[val]._cmd[i + j] != '\0')
	{
		data->cmd[val]._args[j] = data->cmd[val]._cmd[i + j];
		j++;
	}
	data->cmd[val]._args[j] = '\0';
}
/*
void	check_args(t_data *data, int val)
{
	int	i;
	int j;
	int verif;

	j = 0;
	while (data->cmd[val].args[j])
	{
		i = 0;
		while (data->cmd[val].args[j][i] != '\0' && verif == 0)
		{
			if (data->cmd[val].args[j][i] != ' '
				&& data->cmd[val].args[j][i] != '\0')
				verif = 1;
			i++;
		}
		if (verif == 0)
		{
			
		}
		else
			j++;
	}
}*/

void	get_args(t_data *data, int val)
{
	int	i;
	int	len;

	i = data->cmd[val].pos_start_before_cmd_name;
	init_var_args(data, val);
	if (data->cmd[val]._cmd[i] != '\0')
	{
		while (data->cmd[val]._cmd[i] == ' ')
			i++;
		if (data->cmd[val]._cmd[i] != '\0')
		{
			len = get_arg_line_len(data, val, i);
			data->cmd[val]._args = malloc((sizeof(char) * len) + 1);
			if (!data->cmd[val]._args)
				ft_exit(ERRMEMALLOC, data);
			ft_arg_cpy(data, val, i);
			data->cmd[val].args = set_var_args(data, val);
			args_var_env(data, val);
		}
	}
}
