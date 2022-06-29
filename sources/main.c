/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:33 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/22 13:59:08 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 1)
		ft_exit("minishell: No argument needed\n", &data);
	data.exec.envp = env;
	argv = NULL;
	data.p_cmd.nbr_args = 0;
	data.exec.nb_cmd = 0;
	while (1)
	{
		read_line("$> ", &data);
	}
	return (0);
}
