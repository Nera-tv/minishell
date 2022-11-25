/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:45:53 by tweidema          #+#    #+#             */
/*   Updated: 2022/11/25 15:46:03 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
int	ft_execve(t_data *data, int val)
{
	// if (close(data->cmd->pipe.pipeout[0]) < 0)
	// 	return (-1);
	// if (cmd_to_exec == 0 && data->nbr_cmds == 1) // if 1 seule commande
	// {
		// if () //if file input
		// 	;
		// else //Sinon
		// 	;
		// if () //if file output
		// 	;
	// 	else //Sinon
	// 		;
	// }
	// else if (cmd_to_exec == 0)
	// {
	// 	if ()//if file input alors ça (<)
	// 		;
	// 	else // sans file input
	// 	{
	// 		if (dup2(data->cmd->pipe.pipeout[1], 1) < 0
	// 			|| close (data->cmd->pipe.pipeout[1]))
	// 			return (-1);
	// 	}
	// }
	// else if (cmd_to_exec == data->nbr_cmds - 1) // Si dernière commande
	// {
		// if ()//if file output alors ça, attention si append(>>) ou trunc(>)
		// 	;
	// 	else // sans file output
	// 	{
	// 		if (close(data->cmd->pipe.pipeout[1]) < 0
	// 			|| close(data->cmd->pipe.pipeout[0]) < 0
	// 			|| dup2(data->cmd->pipe.pipein[1], 0) < 0
	// 			|| close(data->cmd->pipe.pipein[1]) < 0
	// 			|| close(data->cmd->pipe.pipein[0]) < 0)
	// 			return (-1);
	// 	}
	// }
	// else
	// {
	
	// }
	
	return (0);
}*/

int	save_output(t_data *data, int val)
{
	if (val != 0)
	{
		if (close(data->pipe.pipein[0] < 0)
			|| close(data->pipe.pipein[1] < 0))
			return (-1);
	}
	data->pipe.pipein[0] = data->pipe.pipeout[0];
	data->pipe.pipein[1] = data->pipe.pipeout[1];
	return (0);
}

int	ft_exec(t_data *data, int val)
{
	int	forkid;

	// if (val != data->nbr_cmds - 1)
	// {
		// if (pipe(data->pipe.pipeout) < 0)
		// 	return (-1);
	// }
	forkid = fork();
	if (forkid < 0)
		return (-1);
	if (forkid == 0)
	{
		// if (close(data->pipe.pipeout[0]) < 0
		// 	|| dup2(data->pipe.pipeout[1], 1) < 0
		// 	|| close(data->pipe.pipeout[1]) < 0)
		// {
		// printf("ici\n");
		// 	return (-1);
		// }
		if (execve(data->cmd[val].cmd_path[0],
				data->cmd[val].cmd_path, data->envp) < 0)
		{
			return (-1);
		}
	}
	else
		save_output(data, val);
	return (forkid);
}
