/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:33 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/27 20:54:37 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_data(t_data *data, char **envp, char **argv)
{
	ft_memset(data, 0, sizeof(t_data));
	data->nbr_cmds = 0;
	data->start = 0;
	data->line = NULL;
	data->envp = envp;
	data->argv = argv;
	get_pwd(data);
	data->indic_first_cd = 0;
	data->error = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		ft_exit("Error: no argument needed", &data);
	init_data(&data, envp, argv);
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
