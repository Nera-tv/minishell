/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:17:14 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/22 12:13:07 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(char *msg, t_data *data)
{
	ft_printf(2, msg);
	if (data->cmdl)
		free(data->cmdl);
	exit(0);
}
