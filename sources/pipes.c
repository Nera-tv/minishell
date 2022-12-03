/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:51:43 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/03 12:11:26 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	redirect_pipeout(t_data	*data)
{
	if (close(data->pipeout[0]) < 0 || dup2(data->pipeout[1], 1) < 0
		|| close(data->pipeout[1]) < 0)
		return (-1);
	return (0);
}

int	redirect_pipein(t_data	*data)
{
	if (close(data->pipein[1]) < 0 || dup2(data->pipein[0], 0) < 0
		|| close(data->pipein[0]) < 0)
		return (-1);
	return (0);
}

int	managing_pipes(t_data *data, int val)
{
	if (val == 0)
	{
		dprintf(2, "Première commande\n");
		if (redirect_pipeout(data) < 0) //Rajouter pour les < ou << vu que c'est la première commande
		{
			perror("Erreur première commande");
			return (-1);
		}
	}
	else if (val == data->nbr_cmds - 1)
	{
		dprintf(2, "Dernière commande\n");
		if (redirect_pipein(data) < 0) // rajouter les > ou >> vu que c'est la dernière commande
		{
			perror("Erreur dernière commande");
			return (-1);
		}
	}
	else
	{
		dprintf(2, "En plein millieu des commandes\n");
		if (redirect_pipein(data) < 0 || redirect_pipeout(data) < 0)
		{
			perror("Erreur en plein milleu des commandes");
			return (-1);
		}
	}
	return (0);
}

int	creating_pipes(t_data *data, int val)
{
	if (data->nbr_cmds == 1 && !ft_strchr(data->cmd[val]._cmd, '<')
		&& !ft_strchr(data->cmd[val]._cmd, '>'))
		return (0);
	if (val < data->nbr_cmds - 1)
	{
		dprintf(2, "J'ai crée un pipe !\n");
		if (pipe(data->pipeout) < 0)
		{
			dprintf(2, "Erreur en créant les pipes\n");
			return (-1);
		}
	}
	return (0);
}
