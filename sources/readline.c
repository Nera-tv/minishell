/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:21 by apouchin          #+#    #+#             */
/*   Updated: 2022/07/22 13:46:02 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nbr_cmds)
	{
		if (is_builtins(data, i) > 0)
			exec_builtins(data, i);
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
