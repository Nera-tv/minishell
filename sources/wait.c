/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:48:32 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/05 15:39:45 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	status_to_error(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (1);
}

void	wait_all_pids(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_cmds)
	{
		waitpid(data->forkid[i], &data->status, 0);
		i++;
	} // Peut-être check le status à la fin
	data->err_nbr = status_to_error(data->status);
}
