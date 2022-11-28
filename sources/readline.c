/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:21 by apouchin          #+#    #+#             */
/*   Updated: 2022/11/07 10:55:54 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	lancement(t_data *data)
{
	int	i;
	int	blt;

	i = 0;
	data->forkid = malloc(sizeof(int) * data->nbr_cmds);
	if (!data->forkid)
		ft_exit(ERRMEMALLOC, data);
	while (i < data->nbr_cmds)
	{
		if (data->cmd[i].cmd[0] == '\0')
			return ;
		data->cmd[i].nbr_args = nb_args(data->cmd[i].args);
		if (data->cmd[i].cmd)
		{
			blt = is_builtins(data, i);
			if (blt > 0)
				exec_builtins(data, i, blt);
			else
			{
				search_path(data, i);
				data->forkid[i] = ft_exec(data, i);
				//print_data(data, i);
			}
		}
		i++;
	}
	wait_all_pids(data);
}

void	read_line(const char *prompt, t_data *data)
{
	data->line = readline(prompt);
	if (data->line && *data->line)
		add_history(data->line);
	if (data->line != NULL
		&& ft_strncmp(data->line, "exit", ft_strlen("exit")) == 0)
		ft_exit("exit\n", data);
	if (data->line == NULL)
		ft_exit("exit\n", data);
	get_cmd_arg(data);
	lancement(data);
	free_data_cmd(data);
}
