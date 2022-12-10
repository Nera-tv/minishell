/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:30:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/10 14:31:55 by tweidema         ###   ########.fr       */
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

void	free_data_cmd_bis(t_data *data, int i)
{
	int	j;

	if (data->cmd[i]._args)
		free(data->cmd[i]._args);
	free_args(data->cmd[i].args, nb_args(data->cmd[i].args));
	if (data->cmd[i].args_len)
		free(data->cmd[i].args_len);
	if (data->cmd[i].int_path == 1 && data->cmd[i].cmd_path[0])
		free(data->cmd[i].cmd_path[0]);
	if (data->cmd[i].int_path == 1 && data->cmd[i].cmd_path)
	{
		free(data->cmd[i].cmd_path);
		data->cmd[i].int_path = 0;
	}
	j = 0;
	while (j < data->cmd[i].nb_redir)
	{
		free(data->cmd[i].redirection[j]);
		j++;
	}
	free(data->cmd[i].redirection);
}

void	free_data_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_cmds)
	{
		if (data->cmd[i].cmd[0] != '\0')
			free_data_cmd_bis(data, i);
		if (data->cmd[i].input_method == 2)
			unlink(".minishell_heredoc");
		if (data->cmd[i].output_method)
			free(data->cmd[i].file_output);
		if (data->cmd[i].input_method == 1)
			free (data->cmd[i].file_input);
		free(data->cmd[i].cmd);
		free(data->cmd[i]._cmd);
		i++;
	}
	if (data->cmd)
		free(data->cmd);
	data->nbr_cmds = 0;
	free(data->line);
	if (data->forkid)
	{
		free(data->forkid);
		data->forkid = NULL;
	}
}
