/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/28 12:12:02 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_cmd_name(t_data *data, int val)
{
	int	j;
	int	len;

	len = 0;
	while (data->cmd[val]._cmd[len] != ' '
		&& data->cmd[val]._cmd[len] != '\0' )
		len++;
	data->cmd[val].pos_start_before_cmd_name = len;
	data->cmd[val].cmd = malloc((sizeof(char) * len) + 1);
	if (!data->cmd[val].cmd)
		ft_exit(ERRMEMALLOC, data);
	j = 0;
	while (j < len)
	{
		data->cmd[val].cmd[j] = data->cmd[val]._cmd[j];
		j++;
	}
	data->cmd[val].cmd[j] = '\0';
}
