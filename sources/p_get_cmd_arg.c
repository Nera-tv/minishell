/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_cmd_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:37:43 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 10:48:34 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_cmds(t_data *data, int val)
{
	get_cmd_name(data, val);
	get_args(data, val);
	if (data->cmd[val]._args)
		get_args_len(data, val);
	printf("%s\n", data->cmd[val]._args);
}

void	get_cmd_arg(t_data *data)
{
	int	i;

	data->cmd = NULL;
	if (check_line_pipe(data) == 0)
	{
		get_nbr_cmd(data);
		if (if_only_space(data) == 1)
		{
			i = 0;
			data->cmd = malloc(sizeof(t_cmd) * (data->nbr_cmds + 1));
			if (!data->cmd)
				ft_exit(ERRMEMALLOC, data);
			sep_cmd_pipe(data);
			while (i < data->nbr_cmds)
			{
				init_cmds(data, i);
				i++;
			}
		}
	}
}
