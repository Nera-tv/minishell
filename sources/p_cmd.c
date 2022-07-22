/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/07/22 13:35:43 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_cmd_name(t_data *data, int val)
{
	int i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (data->cmd[val]._cmd[i] == ' ')
		i++;
	while (data->cmd[val]._cmd[i + len] != ' ' && data->cmd[val]._cmd[i + len] != '\0' )
		len++;
	data->cmd[val].pos_start_before_cmd_name = i + len;
	data->cmd[val].cmd = malloc((sizeof(char) * len ) + 1);
	if (!data->cmd[val].cmd)
		ft_exit("allocation error", data);
	j = 0;
	while (i + j < i + len)
	{
		data->cmd[val].cmd[j] = data->cmd[val]._cmd[i + j];
		j++;
	}
	data->cmd[val].cmd[j] = '\0';
	printf("Cmd name %d = %s\n", val, data->cmd[val].cmd);  // COMMANTAIRE ICI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void	init_cmds(t_data *data, int	val)
{
	get_cmd_name(data, val);
	get_args(data, val);
}

void	sep_cmd_pipe(t_data *data)
{
	int	i;
	int len;
	int	old_len;
	int y;
	
	i = 0;
	len = 0;
	old_len = 0;
	while (i < data->nbr_cmds)
	{
		while (data->cmdl[len] != '|' && data->cmdl[len] != '\0')
			len++;
		data->cmd[i]._cmd = malloc(sizeof(char) * ((len - old_len) + 1));
		if (!data->cmd[i]._cmd)
			ft_exit("allocation error", data);
		y = 0;
		while (old_len + y < len)
		{
			data->cmd[i]._cmd[y] = data->cmdl[old_len + y];
			y++;
		}
		data->cmd[i]._cmd[y] = '\0';
		len++;
		old_len = len;
		i++;
	}
}

void	get_cmd_arg(t_data *data)
{
	int	i;
	
	get_nbr_cmd(data);	// recupere le nombre de commande separe par des |
	if (if_only_space(data) == 1)
	{
		i = 0;
		data->cmd = malloc(sizeof(t_cmd) * (data->nbr_cmds + 1)); // malloc pour le nombre de commande separe par les |
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
