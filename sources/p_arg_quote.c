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

char	*ret_db_quote_in_arg(t_data *data, char *line,
		char *var_env, char *replace)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_replace_word(line, var_env, replace, data);
	free(line);
	return (tmp);
}

char	*db_quote_in_arg_bis(t_data *data, char *line, char *var_env)
{
	int		i;
	char	*tmp;
	char	*err_val;

	i = 0;
	tmp = NULL;
	err_val = NULL;
	if (ft_strnncmp(var_env, "$?", 2) == 0)
	{
		err_val = ft_itoa(data->err_nbr);
		tmp = ft_replace_word(line, var_env, err_val, data);
		free(line);
		free(err_val);
		return (tmp);
	}
	while (i < data->nb_env)
	{
		if (ft_cmp_var_env(var_env, data->env[i].name) == 0)
			return (ret_db_quote_in_arg(data, line, var_env, data->env[i].content));
		i++;
	}
	return (ret_db_quote_in_arg(data, line, var_env, "\0"));
}

int	sp_quote_in_arg(char *line, int len)
{
	line = shift_in_tab(line, len);
	while (line[len] != '\0' && line[len] != '\'')
		len++;
	if (line[len] == '\'')
		line = shift_in_tab(line, len);
	if (len > 0)
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
	if (len > 0)
		len--;
	return (len);
}
