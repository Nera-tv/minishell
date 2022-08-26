/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:07:15 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 16:21:12 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	sep_cmd_pipe_bis(t_data *data, int i, int len, int old_len)
{
	int	y;

	len = old_len;
	while (data->cmdl[len] != '|' && data->cmdl[len] != '\0')
		len++;
	data->cmd[i]._cmd = malloc(sizeof(char) * ((len - old_len) + 1));
	if (!data->cmd[i]._cmd)
		ft_exit("allocation error", data);
	y = 0;
	while (old_len + y < len)
	{
		data->cmd[i]._cmd[y] = data->cmdl[old_len + y];
		y++;
	}
	data->cmd[i]._cmd[y] = '\0';
	len++;
	old_len = len;
	return (old_len);
}

void	sep_cmd_pipe(t_data *data)
{
	int	i;
	int	len;
	int	old_len;

	i = 0;
	len = 0;
	old_len = 0;
	while (i < data->nbr_cmds)
	{
		old_len = sep_cmd_pipe_bis(data, i, len, old_len);
		i++;
	}
}
