/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/09/20 17:52:27 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_quote_in_cmd_bis(t_data *data, int val, int len)
{
	char	*line;
	char	*var_env;

	line = data->cmd[val].cmd;
	if (data->cmd[val].cmd[len] == '\"')
		len = db_quote_in_cmd(data, val, len);
	else if (data->cmd[val].cmd[len] == '\'')
		len = sp_quote_in_cmd(data->cmd[val].cmd, len);
	else
	{
		if (line[len] == '$')
		{
			var_env = get_var_env_in_cmd(line);
			line = db_quote_in_cmd_bis(data, line, var_env);
			free(var_env);
		}
	}
	data->cmd[val].cmd = line;
	return (len);
}

void	check_quote_in_cmd(t_data *data, int val)
{
	int		len;

	len = 0;
	while (data->cmd[val].cmd[len] != '\0')
	{
		if (data->cmd[val].cmd[len] != '\\')
			len = check_quote_in_cmd_bis(data, val, len);
		else
		{
			if (data->cmd[val].cmd[len + 1] == '\"'
				|| data->cmd[val].cmd[len + 1] == '\'')
			{
				data->cmd[val].cmd = shift_in_tab(data->cmd[val].cmd, len);
				len += 2;
			}
		}
		if (data->cmd[val].cmd[len] != '\0')
			len++;
	}
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
	printf("%s\n", data->cmd[val].cmd);
	check_quote_in_cmd(data, val);
	printf("%s\n", data->cmd[val].cmd);
}
