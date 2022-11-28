/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:48:32 by tweidema          #+#    #+#             */
/*   Updated: 2022/11/28 13:18:08 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	wait_all_pids(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_cmds)
	{
		waitpid(data->forkid[i], data->status, 0);
		i++;
	} // Peut-être check le status à la fin
}
