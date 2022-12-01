/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:03:30 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/08 12:49:31 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*strdup_until_equal(char *str, t_data *data)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		ft_exit(ERRMEMALLOC, data, 2);
	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*strdup_start_equal(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	i++;
	j = 0;
	while (str[i + j] != '\0')
		j++;
	new = malloc(sizeof(char) * (j + 1));
	if (!new)
		ft_exit(ERRMEMALLOC, data, 2);
	j = 0;
	while (str[i + j] != '\0')
	{
		new[j] = str[i + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

void	ft_lst_env_fill(t_data *data)
{
	int	i;

	i = 0;
	data->nb_env = get_len_for_lst_env(data);
	data->env = malloc(sizeof(t_list_env) * data->nb_env);
	if (!data->env)
		ft_exit(ERRMEMALLOC, data, 2);
	while (data->envp[i])
	{
		data->env[i].name = strdup_until_equal(data->envp[i], data);
		data->env[i].content = strdup_start_equal(data->envp[i], data);
		i++;
	}
	update_val_env(data, ft_strdup("OLDPWD"), NULL);
}
