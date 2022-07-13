/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchin <apouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:33 by dvilard           #+#    #+#             */
/*   Updated: 2022/07/13 12:22:18 by apouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_nbr_arg(t_data *data)
{
	int i;

	i = 0;
	data->cmd.nbr_args++;
	while (data->cmdl[i] != '\0')
	{
		if (data->cmdl[i] == ' ')
		{
			i++;
			data->cmd.nbr_args++;
		}
		i++;
	}
}

void	get_cmd_arg(t_data *data)
{
	get_nbr_arg(data);
	data->cmd.nbr_args = 0;
}


int	main(void)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.cmd.nbr_args = 0;
	while (1)
	{
		if (data.start == 0)
		{
			read_line("$> ", &data);
			data.start = 1;
		}
		else
			read_line("$> ", &data);
	}
	return (0);
}
