/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:40:29 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/22 17:55:33 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_nbr_arg(t_data *data)
{
	int	i;
	
	i = 0;
	while (data->cmdl[i] == ' ')
		i++;
	while (data->cmdl[i])
	{
		if (data->cmdl[i] == ' ' && data->cmdl[i - 1] != ' ')
			data->p_cmd.nbr_args++;
		i++;
	}
}

void	get_cmd_arg(t_data *data)
{
	get_nbr_arg(data);
	printf("%d\n", data->p_cmd.nbr_args);
}
