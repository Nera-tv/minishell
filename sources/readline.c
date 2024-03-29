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

void	if_cmd_not_found(t_data *data, int i)
{
	ft_printf(2, "minishell: %s: command not found\n", data->cmd[i].cmd);
	data->err_nbr = 127;
	ft_exit("", data, data->err_nbr);
}

void	built_or_execve(t_data *data, int i)
{
	int	blt;

	data->forkid[i] = fork();
	if (data->forkid[i] < 0)
		ft_exit(ERRFORK, data, 1);
	if (data->forkid[i] == 0)
	{
		managing_pipes(data, i);
		blt = is_builtins(data, i);
		if (blt > 0)
			exec_builtins(data, i, blt);
		else
		{
			search_path(data, i);
			if (!data->cmd[i].cmd_path || !data->cmd[i].cmd_path[0])
				if_cmd_not_found(data, i);
			ft_exec(data, i);
		}
		ft_exit(NULL, data, data->err_nbr);
	}
	save_output(data, i);
}

void	lancement_bis(t_data *data, int i)
{
	data->cmd[i].nbr_args = nb_args(data->cmd[i].args);
	if (data->cmd[i].cmd)
		built_or_execve(data, i);
}

void	lancement(t_data *data)
{
	int	i;

	i = 0;
	tcsetattr(0, TCSANOW, &data->original);
	data->forkid = malloc(sizeof(int) * data->nbr_cmds);
	if (!data->forkid)
		ft_exit(ERRMEMALLOC, data, 2);
	while (i < data->nbr_cmds)
	{
		if (data->cmd[i]._cmd)
		{
			creating_pipes(data, i);
			if (data->cmd[i].cmd[0] == '\0')
				return ;
			lancement_bis(data, i);
			i++;
		}
	}
	wait_all_pids(data);
	tcsetattr(0, TCSANOW, &data->silent);
}

void	read_line(const char *prompt, t_data *data)
{
	data->line = readline(prompt);
	if (data->line && *data->line)
		add_history(data->line);
	if (data->line == NULL)
		ft_exit("exit\n", data, 0);
	get_cmd_arg(data);
	if (if_blt_only_arg(data) == 0 && data->only_spaces == 0 && data->cmd)
		lancement(data);
	free_data_cmd(data);
}
