/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:21 by apouchin          #+#    #+#             */
/*   Updated: 2022/11/07 10:55:54 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec(t_data *data)
{
	int	i;
	int	blt;

	i = 0;
	while (i < data->nbr_cmds)
	{
		if (data->cmd[i].cmd)
		{
			blt = is_builtins(data, i);
			printf("cmd = %s -- blt = %d\n", data->cmd[i].cmd, blt);
			if (blt > 0)
				exec_builtins(data, i, blt);
			else
			{
				printf("execution de la commande\n");
			}
		}
		i++;
	}
}

void	read_line(const char *prompt, t_data *data)
{
	data->line = readline(prompt);
	if (data->line != NULL
		&& ft_strncmp(data->line, "exit", ft_strlen("exit")) == 0)
		ft_exit("exit\n", data);
	if (data->line == NULL)
		ft_exit("exit\n", data);
	get_cmd_arg(data);
	exec(data);
	free_data_cmd(data);
}
