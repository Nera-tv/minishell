/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neress <neress@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:28:43 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/03 07:21:00 by neress           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    get_args(t_data *data, int val)
{
    int i;
    int j;
    int len;

    i = data->cmd[val].pos_start_before_cmd_name + 1;
    len = 0;
	data->cmd[val]._args = NULL;
    if (data->cmd[val]._cmd[i - 1] != '\0')
    {
    	while (data->cmd[val]._cmd[i + len] != '\0')
				len++;
		data->cmd[val]._args = malloc((sizeof(char) * len ) + 1);
		if (!data->cmd[val]._args)
			ft_exit("allocation error", data);
    	j = 0;
    	while (data->cmd[val]._cmd[i + j] != '\0')
		{
			data->cmd[val]._args[j] = data->cmd[val]._cmd[i + j];
			j++;
		}
    	data->cmd[val]._args[j] = '\0';
		printf("Cmd args %d = %s\n", val, data->cmd[val]._args);  // COMMANTAIRE ICI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}