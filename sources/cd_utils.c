/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:36:56 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/08 13:28:42 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_arg(t_data *data, int val)
{
	int	i;

	i = 0;
	while (data->cmd[val]._args[i] != '\0')
	{
		i++;
		if (data->cmd[val]._args[i] == ' '
			&& (data->cmd[val]._args[i + 1] == ' '
				|| data->cmd[val]._args[i + 1] == '\0'))
			data->cmd[val]._args[i] = '\0';
	}
}
