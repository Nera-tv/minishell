/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_var_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:59 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:29:04 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_var_env_in_arg_bis(char *str, char *env, int i)
{
	int	len;

	len = 0;
	while (if_end_var_env(str[i + len]) != 1)
	{
		env[len] = str[i + len];
		len++;
	}
	env[len] = '\0';
	env[0] = '$';
	return (env);
}

char	*get_var_env_in_arg(char *str, t_data *data)
{
	char	*env;
	int		i;
	int		len;

	i = 0;
	env = NULL;
	while (str[i] != '$')
		i++;
	if (str[i + 1] == '?')
		return (ft_strdup("$?"));
	len = 0;
	str[i] = '0';
	while (if_end_var_env(str[i + len]) != 1)
		len++;
	env = malloc(sizeof(char) * (len + 1));
	if (!env)
		ft_exit(ERRMEMALLOC, data, 2);
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
	else if (arg[len] == '$' && arg[len + 1] != '\0')
	{
		var_env = get_var_env_in_arg(arg, data);
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
		len = parsing_arg_bis(data, val, len, arg_count);
		arg = data->cmd[val].args[arg_count];
		if (arg[len] != '\0' && arg[len] != '\"' && arg[len] != '\'')
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
