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

char	*db_quote_in_cmd_bis(t_data *data, char *line, char *var_env)
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

char	*get_var_env_in_cmd(char *str, t_data *data)
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
	if (!env)
		ft_exit(ERRMEMALLOC, data);
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
