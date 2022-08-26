/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 16:08:09 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_cmd_name(t_data *data, int val)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (data->cmd[val]._cmd[i] == ' ')
		i++;
	while (data->cmd[val]._cmd[i + len] != ' '
		&& data->cmd[val]._cmd[i + len] != '\0' )
		len++;
	data->cmd[val].pos_start_before_cmd_name = i + len;
	data->cmd[val].cmd = malloc((sizeof(char) * len) + 1);
	if (!data->cmd[val].cmd)
		ft_exit("allocation error", data);
	j = 0;
	while (i + j < i + len)
	{
		data->cmd[val].cmd[j] = data->cmd[val]._cmd[i + j];
		j++;
	}
	data->cmd[val].cmd[j] = '\0';
}

void	init_cmds(t_data *data, int val)
{
	get_cmd_name(data, val);
	get_args(data, val);
}

void	get_cmd_arg(t_data *data)
{
	int	i;

	get_nbr_cmd(data);
	if (if_only_space(data) == 1)
	{
		i = 0;
		data->cmd = malloc(sizeof(t_cmd) * (data->nbr_cmds + 1));
		if (!data->cmd)
			ft_exit("allocation error", data);
		sep_cmd_pipe(data);
		while (i < data->nbr_cmds)
		{
			init_cmds(data, i);
			i++;
		}
	}
}
