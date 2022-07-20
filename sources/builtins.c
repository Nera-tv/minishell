/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:46 by dvilard           #+#    #+#             */
/*   Updated: 2022/07/20 15:02:54 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    exec_builtins(t_data *data)
{
    ft_echo(data);
}

int		is_builtins(t_data *data)
{
	if (ft_strnncmp(data->cmdl, "echo", ft_strlen("echo")) == 0)
		return (1);
	return (0);
}