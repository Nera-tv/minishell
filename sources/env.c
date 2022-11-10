/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:53 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/10 21:34:57 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_env)
	{
		if (data->env[i].content)
		{
			ft_putstr_fd(data->env[i].name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(data->env[i].content, 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}
