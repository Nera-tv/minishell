/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_var_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:59 by dvilard           #+#    #+#             */
/*   Updated: 2022/10/27 16:06:46 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_var_env_in_arg(char *str)
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

char	*db_quote_in_arg_bis(t_data *data, char *line, char *var_env)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (data->envp[i])
	{
		if (ft_cmp_var_env(var_env, data->envp[i]) == 0)
		{
			tmp = ft_replace_word(line,
					var_env, data->envp[i]);
			free(line);
			return (tmp);
		}
		i++;
	}
	tmp = ft_replace_word(line, var_env, "=");
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
			var_env = get_var_env_in_arg(line);
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

int	parsing_arg_bis(t_data *data, int val, int len, int arg_count)
{
	char	*var_env;
	char	*arg;

	arg = data->cmd[val].args[arg_count];
	if (arg[len] == '\'')
		len = sp_quote_in_arg(arg, len);
	else if (arg[len] == '\"')
	{
		len = db_quote_in_arg(data, val, len, arg_count);
		arg = data->cmd[val].args[arg_count];
	}
	else if (arg[len] == '$')
	{
		var_env = get_var_env_in_arg(arg);
		arg = db_quote_in_arg_bis(data, arg, var_env);
		free(var_env);
	}
	data->cmd[val].args[arg_count] = arg;
	return (len);
}

char	*parsing_arg(t_data *data, int val, int arg_count)
{
	int		len;
	char	*arg;

	len = 0;
	arg = data->cmd[val].args[arg_count];
	while (arg[len] != '\0')
	{
		if (arg[len] != '\\')
		{
			len = parsing_arg_bis(data, val, len, arg_count);
			arg = data->cmd[val].args[arg_count];
		}
		else
		{
			if (arg[len + 1] == '\'' || arg[len + 1] == '\"')
			{
				arg = shift_in_tab(arg, len);
				len++;
			}
		}
		if (arg[len] != '\0')
			len++;
	}
	return (arg);
}

void	args_var_env(t_data *data, int val)
{
	int	arg_count;
	int	nb_arg;

	arg_count = 0;
	nb_arg = nb_args(data->cmd[val].args);
	while (arg_count < nb_arg)
	{
		data->cmd[val].args[arg_count] = parsing_arg(data, val, arg_count);
		arg_count++;
	}
}
