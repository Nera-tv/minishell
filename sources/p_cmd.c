/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/10/24 16:15:42 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	db_quote_in_cmd(t_data *data, int val, char *line, int len)
{
	char	*var_env;

	line = shift_in_tab(data->cmd[val].cmd, len);
	while (line[len] != '\0' && line[len] != '\"')
	{
		if (line[len] == '\\' && line[len + 1] == '\"')
		{
			line = shift_in_tab(line, len);
			len ++;
		}
		if (line[len] == '$')
		{
			var_env = get_var_env_in_cmd(line);
			line = db_quote_in_cmd_bis(data, line, var_env);
			free(var_env);
		}
		len++;
	}
	line = shift_in_tab(line, len);
	data->cmd[val].cmd = line;
	return (len);
}

int	parsing_cmd_name_bis(t_data *data, int val, int len)
{
	char	*var_env;
	char	*cmd;

	cmd = data->cmd[val].cmd;
	if (cmd[len] == '\'')
		len = sp_quote_in_cmd(cmd, len);
	else if (cmd[len] == '\"')
	{
		len = db_quote_in_cmd(data, val, cmd, len);
		cmd = data->cmd[val].cmd;
	}
	else if (cmd[len] == '$')
	{
		var_env = get_var_env_in_cmd(cmd);
		cmd = db_quote_in_cmd_bis(data, cmd, var_env);
		free(var_env);
	}
	data->cmd[val].cmd = cmd;
	return (len);
}

char	*parsing_cmd_name(t_data *data, int val)
{
	int		len;
	char	*cmd;

	len = 0;
	cmd = data->cmd[val].cmd;
	while (cmd[len] != '\0')
	{
		if (cmd[len] != '\\')
		{
			len = parsing_cmd_name_bis(data, val, len);
			cmd = data->cmd[val].cmd;
		}
		else
		{
			if (cmd[len + 1] == '\'' || cmd[len + 1] == '\"')
			{
				cmd = shift_in_tab(cmd, len);
				len++;
			}
		}
		if (cmd[len] != '\0')
			len++;
	}
	return (cmd);
}

void	get_cmd_name(t_data *data, int val)
{
	int	j;
	int	len;

	len = get_cmd_len(data, val);
	data->cmd[val].pos_start_before_cmd_name = len;
	data->cmd[val].cmd = malloc((sizeof(char) * len) + 1);
	if (!data->cmd[val].cmd)
		ft_exit(ERRMEMALLOC, data);
	j = 0;
	while (j < len)
	{
		data->cmd[val].cmd[j] = data->cmd[val]._cmd[j];
		j++;
	}
	data->cmd[val].cmd[j] = '\0';
	data->cmd[val].cmd = parsing_cmd_name(data, val);
	printf("%s\n", data->cmd[val].cmd);
}
