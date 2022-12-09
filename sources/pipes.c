/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:51:43 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/09 11:35:35 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirect_pipeout(t_data	*data, int val)
{
	int	fd;

	fd = 0;
	if (close(data->pipeout[0]) < 0 || dup2(data->pipeout[1], 1) < 0
		|| close(data->pipeout[1]) < 0)
		ft_exit(ERRPIPE, data, 1);
	fd = opening_file_output(data, val);
	if (fd)
		dup2(fd, 1);
}

void	redirect_pipein(t_data	*data, int val)
{
	int	fd;

	fd = 0;
	if (val)
		;
	if (close(data->pipein[1]) < 0 || dup2(data->pipein[0], 0) < 0
		|| close(data->pipein[0]) < 0)
		ft_exit(ERRPIPE, data, 1);
	if (fd)
		dup2(fd, 0);
}

int	managing_pipes(t_data *data, int val)
{
	if (val == 0)
		redirect_pipeout(data, val); //Rajouter pour les < ou << vu que c'est la première commande
	else if (val == data->nbr_cmds - 1)
		redirect_pipein(data, val); // rajouter les > ou >> vu que c'est la dernière commande
	else // rajouter ici le check des 2 au dessus
	{
		redirect_pipein(data, val);
		redirect_pipeout(data, val);
	}
	return (0);
}

int	creating_pipes(t_data *data, int val)
{
	if (data->nbr_cmds == 1 && !ft_strchr(data->cmd[val]._cmd, '<')
		&& !ft_strchr(data->cmd[val]._cmd, '>'))
		return (0);
	get_me_file_redirect(data, val);
	if (val < data->nbr_cmds - 1)
	{
		if (pipe(data->pipeout) < 0)
			ft_exit(ERRPIPE, data, 1);
	}
	return (0);
}
