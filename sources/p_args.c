/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:28:43 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 19:46:55 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	verif_args(t_data *data, int val)
{
	if (data->cmd[val]._args[0] == '\0')
	{
		free(data->cmd[val]._args);
		data->cmd[val]._args = NULL;
	}
	if (data->cmd[val].arg[0] == '\0')
	{
		free(data->cmd[val].arg);
		data->cmd[val].arg = NULL;
	}
}

void	get_args_bis(t_data *data, int val)
{
	int	i;
	int	j;

	if (data->cmd[val]._args)
	{
		data->cmd[val].arg = malloc(sizeof (char *)
				* (ft_strlen_m(data->cmd[val]._args) + 1));
		i = 0;
		while (data->cmd[val]._args[i] == ' ')
			i++;
		j = 0;
		while (data->cmd[val]._args[i + j] != '\0')
		{
			data->cmd[val].arg[j] = data->cmd[val]._args[i + j];
			j++;
		}
		data->cmd[val].arg[j] = '\0';
	}
	data->cmd[val].args = ft_split(data->cmd[val].arg, ' ');
}

void	init_var_args(t_data *data, int val)
{
	data->cmd[val]._args = NULL;
	data->cmd[val].arg = NULL;
	data->cmd[val].args = NULL;
}

void	get_args(t_data *data, int val)
{
	int	i;
	int	j;
	int	len;

	i = data->cmd[val].pos_start_before_cmd_name + 1;
	len = 0;
	init_var_args(data, val);
	if (data->cmd[val]._cmd[i - 1] != '\0')
	{
		while (data->cmd[val]._cmd[i + len] != '\0')
				len++;
		data->cmd[val]._args = malloc((sizeof(char) * len) + 1);
		if (!data->cmd[val]._args)
			ft_exit("allocation error", data);
		j = 0;
		while (data->cmd[val]._cmd[i + j] != '\0')
		{
			data->cmd[val]._args[j] = data->cmd[val]._cmd[i + j];
			j++;
		}
		data->cmd[val]._args[j] = '\0';
		get_args_bis(data, val);
		verif_args(data, val);
	}
}
