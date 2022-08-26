/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:40 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 01:12:46 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	if_only_space(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmdl[i] != '\0')
	{
		if (data->cmdl[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	get_nbr_cmd(t_data *data)
{
	int	i;

	data->nbr_cmds++;
	i = 0;
	while (data->cmdl[i++] != '\0')
	{
		if (data->cmdl[i] == '|')
			data->nbr_cmds++;
	}
}
