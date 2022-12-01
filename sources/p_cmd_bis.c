/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:19:01 by dvilard           #+#    #+#             */
/*   Updated: 2022/10/27 15:39:36 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*shift_in_tab_pro(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '$')
		i++;
	tab = shift_in_tab(tab, i);
	return (tab);
}

char	*ret_db_quote_in_cmd(t_data *data, char *line,
		char *var_env, char *replace)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_replace_word(line, var_env, replace, data);
	free(line);
	return (tmp);
}

char	*db_quote_in_cmd_bis(t_data *data, char *line, char *var_env)
{
	int		i;
	char	*tmp;
	char	*err_val;

	i = 0;
	tmp = NULL;
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
		if (ft_cmp_var_env(data->env[i].name, var_env) == 0)
			return (ret_db_quote_in_cmd(data, line,
					var_env, data->env[i].content));
		i++;
	}
	return (ret_db_quote_in_cmd(data, line, var_env, "\0"));
}

char	*get_var_env_in_cmd_bis(char *str, char *env, int i)
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

char	*get_var_env_in_cmd(char *str, t_data *data)
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
	env = get_var_env_in_cmd_bis(str, env, i);
	str[i] = '$';
	return (env);
}
