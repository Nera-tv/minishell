/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/07/21 00:29:26 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_nbr_cmd(t_data *data)
{
	int	i;

	data->nbr_cmds++;
	i = 0;
	while (data->cmdl[i++] != '\0')
	{
		if (data->cmdl[i] == '|')
			data->nbr_cmds++;
	}
}

void	get_cmd_name(t_data *data, int val)
{
	int i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (data->cmdl[i] == ' ')
		i++;
	while (data->cmdl[i + len] != ' ' && data->cmdl[i + len] != '\0' )
		len++;
	data->cmd[val].cmd = malloc(sizeof(char *) * len);
	if (!data->cmd[val].cmd)
		ft_exit("allocation error", data);
	while (j < len)
	{
		// Copie de cmdl vers cmd.cmd
	}
	printf("%s\n", data->cmd[val].cmd);
}

void	init_cmds(t_data *data, int	val)
{
	data->cmd = malloc(sizeof(t_cmd *) * data->nbr_cmds); // malloc pour le nombre de commande separe par les |
	get_cmd_name(data, val);
}

void	get_cmd_arg(t_data *data)
{
	int	i;
	
	get_nbr_cmd(data);	// recupere le nombre de commande separe par des |
	if (if_only_space(data) == 1)
	{
		i = 0;
		while (i <= data->nbr_cmds)
		{
			init_cmds(data, i);
			i++;
		}
	}
}
