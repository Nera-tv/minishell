/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:19:01 by dvilard           #+#    #+#             */
/*   Updated: 2022/09/20 17:55:36 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*db_quote_in_cmd_bis(t_data *data, char *line, char *var_env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->envp[i])
	{
		if (ft_cmp_var_env(var_env, data->envp[i]) == 0)
		{
			tmp = ft_replace_word(line,
					var_env, data->envp[i]);
			free(line);
			line = tmp;
		}
		i++;
	}
	return (line);
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
	return (env);
}

char	*shift_in_tab(char *tab, int i)
{
	while (tab[i] != '\0')
	{
		tab[i] = tab[i + 1];
		i++;
	}
	return (tab);
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
	return (len);
}
/*
*gestion des var env (si connue la remplace, sinon
	enleve toute la suite jusqu'a l'espace, ' ou ");
*dois laisser les \ (sauf si db quote  ), les '.
*/

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
