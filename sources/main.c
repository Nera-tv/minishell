/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:33 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/08 10:58:43 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_data(t_data *data, char **envp, char **argv)
{
	ft_memset(data, 0, sizeof(t_data));
	g_status = 0;
	init_sig_callbacks(0);
	data->cmd = NULL;
	data->nbr_cmds = 0;
	data->start = 0;
	data->line = NULL;
	data->envp = envp;
	data->argv = argv;
	get_pwd(data);
	data->indic_first_cd = 0;
	ft_lst_env_fill(data);
	put_path_data(data);
	data->status = 0;
	data->err_nbr = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		ft_exit("Error: no argument needed", &data, 2);
	init_data(&data, envp, argv);
	tcgetattr(0, &data.original);
	data.silent = data.original;
	data.silent.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &data.silent);
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
//UPDATE OLDPWD