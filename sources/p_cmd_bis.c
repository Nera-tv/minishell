/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:19:01 by dvilard           #+#    #+#             */
/*   Updated: 2022/09/27 15:21:01 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *shift_in_tab_pro(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '$')
		i++;
	tab = shift_in_tab(tab, i);
	return (tab);
}

char	*db_quote_in_cmd_bis(t_data *data, char *line, char *var_env)
{
	int		i;
	int		if_var;
	char	*tmp;

	i = 0;
	if_var = 0;
	while (data->envp[i])
	{
		if (ft_cmp_var_env(var_env, data->envp[i]) == 0)
		{
			tmp = ft_replace_word(line,
					var_env, data->envp[i]);
			free(line);
			line = tmp;
			if_var = 1;
		}
		i++;
	}
	if (if_var == 1)
		return (line);
	else
		return (del_var_env_in_line(line));
}

char	*get_var_env_in_cmd(char *str)
{
	char	*env;
	int		i;
	int		len;

	i = 0;
	env = NULL;
	while (str[i] != '$')
		i++;
	len = 0;
	str[i] = '0';
	while (if_end_var_env(str[i + len]) != 1)
		len++;
	env = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (if_end_var_env(str[i + len]) != 1)
	{
		env[len] = str[i + len];
		len++;
	}
	env[len] = '\0';
	env[0] = '$';
	str[i] = '$';
	return (env);
}

int	db_quote_in_cmd(t_data *data, int val, int len)
{
	char	*var_env;
	char	*line;

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
	return (len - 1);
}

int	sp_quote_in_cmd(char *line, int len)
{
	line = shift_in_tab(line, len);
	while (line[len] != '\0' && line[len] != '\'')
		len++;
	if (line[len] == '\'')
		line = shift_in_tab(line, len);
	len--;
	return (len);
}
