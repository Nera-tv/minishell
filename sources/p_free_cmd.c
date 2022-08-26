/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:30:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 01:26:55 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_data_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_cmds)
	{
		free(data->cmd[i].cmd);
		free(data->cmd[i]._cmd);
		if (data->cmd[i]._args)
			free(data->cmd[i]._args);
		i++;
	}
	free(data->cmd);
	data->nbr_cmds = 0;
	free(data->cmdl);
}
