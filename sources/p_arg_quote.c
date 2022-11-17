/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_arg_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:16:09 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:29:19 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*db_quote_in_arg_bis(t_data *data, char *line, char *var_env)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < data->nb_env)
	{
		if (ft_cmp_var_env(var_env, data->env[i].name) == 0)
		{
			tmp = ft_replace_word(line,
					var_env, data->env[i].content, data);
			free(line);
			return (tmp);
		}
		i++;
	}
	tmp = ft_replace_word(line, var_env, "\0", data);
	free(line);
	return (tmp);
}

int	sp_quote_in_arg(char *line, int len)
{
	line = shift_in_tab(line, len);
	while (line[len] != '\0' && line[len] != '\'')
		len++;
	if (line[len] == '\'')
		line = shift_in_tab(line, len);
	len--;
	return (len);
}

int	db_quote_in_arg(t_data *data, int val, int len, int arg_count)
{
	char	*var_env;
	char	*line;

	line = shift_in_tab(data->cmd[val].args[arg_count], len);
	while (line[len] != '\0' && line[len] != '\"')
	{
		if (line[len] == '\\' && line[len + 1] == '\"')
		{
			line = shift_in_tab(line, len);
			len ++;
		}
		if (line[len] == '$')
		{
			var_env = get_var_env_in_arg(line, data);
			line = db_quote_in_arg_bis(data, line, var_env);
			free(var_env);
		}
		if (line[len] != '\"' && line[len] != '\0')
			len++;
	}
	line = shift_in_tab(line, len);
	data->cmd[val].args[arg_count] = line;
	return (len);
}
