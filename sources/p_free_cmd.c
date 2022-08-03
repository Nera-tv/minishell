/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neress <neress@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:30:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/03 07:21:09 by neress           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_data_cmd(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nbr_cmds)
	{
		free(data->cmd[i].cmd);
		free(data->cmd[i]._cmd);
		if (data->cmd[i]._args)
			free(data->cmd[i]._args);
		i++;
	}
	free(data->cmd); // <!> ne semble pas fonctionner pour les leaks, a revoir <!>
	data->nbr_cmds = 0;
	free(data->cmdl);
}
