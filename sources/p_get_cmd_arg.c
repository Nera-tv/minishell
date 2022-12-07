/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_cmd_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:37:43 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 10:48:34 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_nb_redir(t_data *data, int val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->cmd[val]._cmd[i] != '\0')
	{
		if (data->cmd[val]._cmd[i] == '<')
		{
			if (data->cmd[val]._cmd[i + 1] != '<')
				j++;
		}
		else if (data->cmd[val]._cmd[i] == '>')
		{
			if (data->cmd[val]._cmd[i + 1] != '>')
				j++;
		}
		i++;
	}
	return (j);
}

char	*cp_redir(char *str, int i, t_data *data)
{
	int		j;
	char	*ret;

	
	return (ret);
}

void	get_redir(t_data *data, int val)
{
	int	i;
	int	j;

	i = 0;
	data->cmd[val].nb_redir = get_nb_redir(data, val);
	data->cmd[val].redirection = malloc(sizeof(char *)
		* data->cmd[val].nb_redir);
	if (!data->cmd[val].redirection)
		ft_exit(ERRMEMALLOC, data, 2);
	j = 0;
	while (data->cmd[val]._cmd[i] != '\0')
	{
		if (data->cmd[val]._cmd[i] == '<' || data->cmd[val]._cmd[i] == '>')
		{
			data->cmd[val].redirection[j] = cp_redir(data->cmd[val]._cmd, i, data);
			printf("%s\n", data->cmd[val].redirection[j]);
			data->cmd[val]._cmd = ft_replace_word(data->cmd[val]._cmd, data->cmd[val].redirection[j], "", data);
			j++;
		}
		i++;
	}
	printf("%s\n", data->cmd[val]._cmd);
}

void	init_cmds(t_data *data, int val)
{
	get_redir(data, val);
	get_cmd_name(data, val);
	if (data->cmd[val].cmd[0] == '\0')
		return ;
	get_args(data, val);
	data->cmd[val].nbr_args = nb_args(data->cmd[val].args);
	if (data->cmd[val]._args)
		get_args_len(data, val);
}

int	check_line(t_data *data)
{
	if (check_line_pipe(data) == 1)
		return (1);
	return (0);
}

void	get_cmd_arg(t_data *data)
{
	int	i;

	data->cmd = NULL;
	if (check_line(data) == 0)
	{
		get_nbr_cmd(data);
		if (if_only_space(data) == 1)
		{
			i = 0;
			data->cmd = malloc(sizeof(t_cmd) * (data->nbr_cmds + 1));
			if (!data->cmd)
				ft_exit(ERRMEMALLOC, data, 2);
			sep_cmd_pipe(data);
			while (i < data->nbr_cmds)
			{
				init_cmds(data, i);
				i++;
			}
		}
	}
}
