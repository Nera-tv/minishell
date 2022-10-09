/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/09/29 14:00:48 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*var_dollard_dollard(char *line)
{
	char	var_env[3];
	char	*tmp;
	
	var_env[0] = '$';
	var_env[1] = '$';
	var_env[2] = '\0';
	tmp = ft_replace_word(line, var_env, "=50");
	free(line);
	line = tmp;
	return (line);
}

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
		if (line[len] == '$' && if_end_var_env(line[len + 1]) != 1)
		{
			var_env = get_var_env_in_cmd(line);
			line = db_quote_in_cmd_bis(data, line, var_env);
			free(var_env);
			data->cmd[val].cmd = line;
		}
		else if (line[len + 1] != '$' && if_end_var_env(line[len + 1]) == 1)
			len++;
		else if (line[len + 1] == '$')
			data->cmd[val].cmd = var_dollard_dollard(line);
	}
	return (len);
}

void	check_quote_in_cmd(t_data *data, int val)
{
	int		len;

	len = 0;
	while (data->cmd[val].cmd[len] != '\0')
	{
		//printf("%d : %c\n",len , data->cmd[val].cmd[len]);
		//printf("%s\n", data->cmd[val].cmd);
		if (data->cmd[val].cmd[len] != '\\')
			len = check_quote_in_cmd_bis(data, val, len);
		else
		{
			if (data->cmd[val].cmd[len + 1] == '\"'
				|| data->cmd[val].cmd[len + 1] == '\'')
			{
				data->cmd[val].cmd = shift_in_tab(data->cmd[val].cmd, len);
				len += 1;
			}
		}
		if (data->cmd[val].cmd[len] != '\0' && data->cmd[val].cmd[len] != '$')
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
	check_quote_in_cmd(data, val);
	printf("%s\n", data->cmd[val].cmd);
}
