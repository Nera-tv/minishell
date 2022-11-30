/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:51:43 by tweidema          #+#    #+#             */
/*   Updated: 2022/11/30 12:25:22 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	input_pipes(t_data *data)
{
	if (data->nbr_cmds == 1 && !ft_strchr(data->cmd[0].cmd, '<'))
		return (0);
	else if (ft_strchr())
}
