/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:17:14 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/10 20:39:46 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(char *msg, t_data *data)
{
	int	j;

	ft_printf(2, msg);
	free(data->line);
	free(data->pwd);
	j = 0;
	if (data->indic_first_cd == 1)
	{
		while (j < data->nb_env)
		{
			free(data->env[j].content);
			j++;
		}
	}
	exit(0);
}
