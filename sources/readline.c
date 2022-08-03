/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neress <neress@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:21 by apouchin          #+#    #+#             */
/*   Updated: 2022/08/03 07:33:23 by neress           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec(t_data *data)
{
	int i;
	int blt;

	i = 0;
	while (i < data->nbr_cmds)
	{
		blt = is_builtins(data, i);
		if (blt > 0)
			exec_builtins(data, i, blt);
		else
		{
			//parti execution
			
			
			//preparation pour la commande suivante
			
		}
		i++;
	}
}

void	read_line(const char *prompt, t_data *data)
{
	data->cmdl = readline(prompt);
	if (data->cmdl != NULL && ft_strncmp(data->cmdl, "exit", ft_strlen("exit")) == 0)
		ft_exit("exit\n", data);
	if (data->cmdl == NULL)
		ft_exit("exit\n", data);
	get_cmd_arg(data);
	exec(data);
	free_data_cmd(data);
}
