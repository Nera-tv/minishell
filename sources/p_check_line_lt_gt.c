/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_line_lt_gt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:16 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/08 12:02:22 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_line_only_lt_gt(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] == ' ')
		i++;
	while (data->line[i] != '\0')
	{
		if (data->line[i] == '<')
		{
		}
		if (data->line[i] == '>')
		{
		}
		if (data->line[i] != '\0')
			i++;
	}
	return (0);
}

int	check_line_lt_gt(t_data *data)
{
	if (check_line_only_lt_gt(data) == 1)
		return (1);
	return (0);
}
