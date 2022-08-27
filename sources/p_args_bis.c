/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:37:38 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/27 20:54:45 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_quotes(t_data *data, int val)
{
	int	i;

	i = 0;
	while (data->cmd[val].args[i])
	{
		i++;
	}
}

void	check_dbl_quotes(t_data *data, int val)
{
	int	i;

	i = 0;
	while (data->cmd[val].args[i])
	{
		i++;
	}
}
