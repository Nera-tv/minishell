/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:45:53 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/09 16:41:10 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	save_output(t_data *data, int val)
{
	if (val != 0)
	{
		if (close(data->pipein[0]) < 0
			|| close(data->pipein[1]) < 0)
			ft_exit(ERRFD, data, 2);
	}
	data->pipein[0] = data->pipeout[0];
	data->pipein[1] = data->pipeout[1];
	return (0);
}

int	ft_exec(t_data *data, int val)
{
	if (execve(data->cmd[val].cmd_path[0],
			data->cmd[val].cmd_path, data->envp) < 0)
	{
		perror(data->cmd[val].cmd);
		ft_exit(NULL, data, 2);
	}
	return (0);
}
