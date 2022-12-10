/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:30:11 by dvilard           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/10 14:31:55 by tweidema         ###   ########.fr       */
=======
/*   Updated: 2022/12/09 17:22:03 by dvilard          ###   ########.fr       */
>>>>>>> 0319c2e4e3b72f879fad28095570ac6252a9b32c
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

void	free_data_cmd_redir(t_data *data, int i)
{
	free(data->cmd[i].cmd);
	free(data->cmd[i]._cmd);
	free(data->cmd[i].redirection);
}

void	free_data_cmd_bis(t_data *data, int i)
{
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
}

void	free_data_cmd(t_data *data)
{
	int	i;

	i = 0;
	if (data->only_spaces == 0)
	{
<<<<<<< HEAD
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
=======
		while (i < data->nbr_cmds)
		{
			if (data->cmd[i].cmd[0] != '\0')
				free_data_cmd_bis(data, i);
			if (data->cmd[i].input_method == 2)
				unlink(".minishell_heredoc");
			free_data_cmd_redir(data, i);
			i++;
		}
		if (data->cmd)
			free(data->cmd);
>>>>>>> 0319c2e4e3b72f879fad28095570ac6252a9b32c
	}
	data->nbr_cmds = 0;
	free(data->line);
	if (data->forkid)
	{
		free(data->forkid);
		data->forkid = NULL;
	}
}
