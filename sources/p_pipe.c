/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:07:15 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/01 10:30:48 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_cmd_pipe_len(t_data *data, int old_len)
{
	int	len;

	len = old_len;
	while (data->line[len] != '|' && data->line[len] != '\0')
		len++;
	len--;
	while (data->line[len] == ' ')
		len--;
	return (len);
}

int	sep_cmd_pipe_bis(t_data *data, int i, int old_len)
{
	int	y;
	int	len;

	len = get_cmd_pipe_len(data, old_len);
	data->cmd[i]._cmd = malloc(sizeof(char) * ((len - old_len) + 2));
	if (!data->cmd[i]._cmd)
		ft_exit(ERRMEMALLOC, data, 2);
	y = 0;
	while (data->line[old_len + y] == ' ')
		old_len++;
	while (old_len + y <= len)
	{
		data->cmd[i]._cmd[y] = data->line[old_len + y];
		y++;
	}
	data->cmd[i]._cmd[y] = '\0';
	while (data->line[len] != '|' && data->line[len] != '\0')
		len++;
	len++;
	old_len = len;
	return (old_len);
}

void	sep_cmd_pipe(t_data *data)
{
	int	i;
	int	old_len;

	i = 0;
	old_len = 0;
	while (i < data->nbr_cmds)
	{
		old_len = sep_cmd_pipe_bis(data, i, old_len);
		i++;
	}
}
