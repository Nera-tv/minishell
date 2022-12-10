/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:51:43 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/10 14:35:42 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirect_pipeout(t_data	*data, int val)
{
	int	fd;

	fd = 0;
	if (val != data->nbr_cmds - 1)
	{
		if (close(data->pipeout[0]) < 0 || dup2(data->pipeout[1], 1) < 0
			|| close(data->pipeout[1]) < 0)
			ft_exit(ERRPIPE, data, 1);
	}
	fd = opening_file_output(data, val);
	if (fd)
	{
		if (dup2(fd, 1) < 0)
			ft_exit(ERRFD, data, 2);
	}
}

void	redirect_pipein(t_data	*data, int val)
{
	int	fd;

	fd = 0;
	if (val != 0)
	{
		if (close(data->pipein[1]) < 0 || dup2(data->pipein[0], 0) < 0
			|| close(data->pipein[0]) < 0)
			ft_exit(ERRPIPE, data, 1);
	}
	fd = opening_file_input(data, val);
	if (fd)
	{
		if (dup2(fd, 0))
			ft_exit(ERRFD, data, 2);
	}
}

int	managing_pipes(t_data *data, int val)
{
	redirect_pipein(data, val);
	redirect_pipeout(data, val);
	return (0);
}

int	creating_pipes(t_data *data, int val)
{
	if (data->nbr_cmds == 1 && !data->cmd[val].redirection)
		return (0);
	get_me_file_redirect(data, val);
	if (val < data->nbr_cmds - 1)
	{
		if (pipe(data->pipeout) < 0)
			ft_exit(ERRPIPE, data, 1);
	}
	return (0);
}
