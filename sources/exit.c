/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:17:14 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/28 14:22:36 by dvilard          ###   ########.fr       */
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
		while (data->envp[j])
		{
			if (ft_strnncmp(data->envp[j], "PWD=", ft_strlen("PWD=")) == 0)
				free(data->envp[j]);
			j++;
		}
	}
	exit(0);
}
