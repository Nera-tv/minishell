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

void	built_or_execve(t_data *data, int i)
{
	int	blt;

	data->forkid[i] = fork();
	if (data->forkid[i] < 0)
		ft_exit(ERRFORK, data, 1);
	if (data->forkid[i] == 0)
	{
		if (data->nbr_cmds > 1)
			managing_pipes(data, i);
		blt = is_builtins(data, i);
		if (blt > 0)
			exec_builtins(data, i, blt);
		else
		{
			search_path(data, i);
			ft_exec(data, i);
		}
		ft_exit(NULL, data, 0);
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

int	if_blt_only_arg_bis(t_data *data, int indic)
{
	if (indic == 1)
	{
		exit_if_blt_exit(data, 0);
		return (1);
	}
	else if (indic == 2)
	{
		ft_export(data, 0);
		return (1);
	}
	else if (indic == 3)
	{
		ft_unset(data, 0);
		return (1);
	}
	else if (indic == 4)
	{
		ft_cd(data, 0);
		return (1);
	}
	return (0);
}

int	if_blt_only_arg(t_data *data)
{
	if (data->cmd && data->cmd[0].cmd \
		&& ft_strnncmp(data->cmd[0].cmd, "exit", ft_strlen("exit")) == 0 \
		&& data->cmd[0].cmd[4] == '\0' && data->nbr_cmds == 1)
		return (if_blt_only_arg_bis(data, 1));
	if (data->cmd && data->cmd[0].cmd \
		&& ft_strnncmp(data->cmd[0].cmd, "export", ft_strlen("export")) == 0 \
		&& data->cmd[0].cmd[6] == '\0' && data->nbr_cmds == 1)
		return (if_blt_only_arg_bis(data, 2));
	if (data->cmd && data->cmd[0].cmd \
		&& ft_strnncmp(data->cmd[0].cmd, "unset", ft_strlen("unset")) == 0 \
		&& data->cmd[0].cmd[5] == '\0' && data->nbr_cmds == 1)
		return (if_blt_only_arg_bis(data, 3));
	if (data->cmd && data->cmd[0].cmd \
		&& ft_strnncmp(data->cmd[0].cmd, "cd", ft_strlen("cd")) == 0 \
		&& data->cmd[0].cmd[2] == '\0' && data->nbr_cmds == 1)
		return (if_blt_only_arg_bis(data, 4));
	return (0);
}

void	read_line(const char *prompt, t_data *data)
{
	data->line = readline(prompt);
	if (data->line && *data->line)
		add_history(data->line);
	if (data->line == NULL)
		ft_exit("exit\n", data, 0);
	get_cmd_arg(data);
	if (if_blt_only_arg(data) == 0 && data->only_spaces == 0)
		lancement(data);
	free_data_cmd(data);
}

/*
**	//printf("data->line ==%s==\n", data->line);
**	//dprintf(2, "%s %d\n", strerror(errno), errno);
**	//sleep(100);
**	//close(0);
*/