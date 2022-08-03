/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neress <neress@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:33 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/03 07:26:20 by neress           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*

void	get_nbr_arg(t_data *data)
{
	int i;

	i = 0;
	data->cmd.nbr_args++; // met le compteur d'arg a 1
	while (data->cmdl[i] == ' ')  // vas jusqu'au premier argument
		i++;
	while (data->cmdl[i] != '\0')
	{
		if (data->cmdl[i] == ' ' && data->cmdl[i + 1] != ' ' && data->cmdl[i + 1] != '\0')
		{
			i++;
			data->cmd.nbr_args++;
		}
		i++;
	}
}*/

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		ft_exit("Error: no argument needed", &data);
	ft_memset(&data, 0, sizeof(t_data));
	data.nbr_cmds = 0;
	data.envp = envp;
	data.argv = argv;
	while (1)
	{
		if (data.start == 0) //verifie si c'est la premier commande ou non (pour de l'affichage)
		{
			read_line("$> ", &data);
			data.start = 1;
		}
		else
			read_line("$> ", &data);
	}
	return (0);
}
