/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:57 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:31:11 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_matricelen(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i])
	{
		i++;
	}
	return (i);
}

void	ft_export(t_data *data, int val)
{
	if (!data->cmd[val]._args)
	{
		ft_sort_and_print_env(ft_matricelen(data->envp), data->envp, data);
	}
	else
	{
	}
}
