/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_back_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:40:30 by dvilard           #+#    #+#             */
/*   Updated: 2022/09/20 15:24:30 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen_c_to_c(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] != '\0')
	{
		i++;
		while (s[i] != c)
		{
			if (s[i] == '\0')
				return (i);
			i++;
		}
	}
	return (i);
}

void	remove_quote_in_back_slash(t_data *data, int val, int arg_count)
{
	int	i;

	i = ft_strlen_c_to_c(data->cmd[val].args[arg_count], '\\');
	printf("%d\n", i);
}
/*
void	remove_back_slash(t_data *data, int val, int arg_count, int i)
{
	
	
	int		y;
	char	*tmp;

	y = 0;
	tmp = data->cmd[val].args[arg_count];
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\\' && tmp[i + 1] == '\\')
			i++;
		else
		{
			data->cmd[val].args[arg_count][y] = tmp[i];
			y++;
			i++;
		}
	}
	data->cmd[val].args[arg_count][y] = '\0';
}*/

void	if_back_slash_bis(t_data *data, int val, int arg_count, char *var_env)
{
	char	*tmp;
	int		i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_cmp_var_env(var_env, data->envp[i]) == 0)
		{
			tmp = ft_replace_word(data->cmd[val].args[arg_count],
					var_env, data->envp[i]);
			free(data->cmd[val].args[arg_count]);
			data->cmd[val].args[arg_count] = tmp;
		}
		i++;
	}
}

int	if_back_slash(t_data *data, int val, int arg_count, int i)
{
	int		dollar_count;
	char	*var_env;

	dollar_count = if_var_env(data->cmd[val].args[arg_count], '\\');
	printf("%d\n", dollar_count);
	if (dollar_count != 0)
	{
		var_env = get_var_env_in_arg(data->cmd[val].args[arg_count]);
		if_back_slash_bis(data, val, arg_count, var_env);
		free(var_env);
	}
	printf("%d\n", i);
	return (ft_strlen(data->cmd[val].args[arg_count]));
}
