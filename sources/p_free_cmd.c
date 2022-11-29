/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:30:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/29 16:07:16 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_args(char **args, int nbr_args)
{
	int	i;

	i = 0;
	while (i < nbr_args)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_data_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_cmds)
	{
		if (data->cmd[i].cmd[0] != '\0')
		{
			if (data->cmd[i]._args)
				free(data->cmd[i]._args);
			free_args(data->cmd[i].args, nb_args(data->cmd[i].args));
			if (data->cmd[i].args_len)
				free(data->cmd[i].args_len);
			if (data->int_path == 1 && data->cmd[i].cmd_path[0])
				free(data->cmd[i].cmd_path[0]);
			if (data->int_path == 1 && data->cmd[i].cmd_path)
			{
				free(data->cmd[i].cmd_path);
				data->int_path = 0;
			}
		}
		free(data->cmd[i].cmd);
		free(data->cmd[i]._cmd);
		i++;
	}
	if (data->cmd)
		free(data->cmd);
	data->nbr_cmds = 0;
	free(data->line);
	free(data->forkid);
}
