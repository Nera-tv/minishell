/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:33 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 01:12:14 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		ft_exit("Error: no argument needed", &data);
	ft_memset(&data, 0, sizeof(t_data));
	data.nbr_cmds = 0;
	data.envp = envp;
	data.argv = argv;
	get_pwd(&data);
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
