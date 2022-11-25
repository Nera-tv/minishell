/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:52:25 by tweidema          #+#    #+#             */
/*   Updated: 2022/11/25 13:48:23 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_data(t_data *data, int val)
{
	int i;
	
	data->cmd[val].nbr_args = nb_args(data->cmd[val].args);
	printf("------------------------------------------\n");
	printf("nbr_cmds = %d\n", data->nbr_cmds);
	printf("line = %s\n", data->line);
	printf("pwd = %s\n", data->pwd);
	printf("cmd name = %s\n", data->cmd[val].cmd);
	if (data->cmd[val].cmd_path[0])
		printf("cmd path = %s\n", data->cmd[val].cmd_path[0]);
	printf("------------------------------------------\n");
	i = 0;
	if (data->cmd[val]._args)
	{
		while (i < data->cmd[val].nbr_args)
		{
			printf("arg[%d] = %s\n", i, data->cmd[val].args[i]);
			i++;
		}
	}
	printf("------------------------------------------\n");
}
