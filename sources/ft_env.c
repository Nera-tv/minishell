/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:46:24 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/08 12:54:07 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	new_env(t_data *data, char *name, char *content)
{
	t_list_env	*env_tab;
	int			i;

	env_tab = malloc(sizeof(t_list_env) * (data->nb_env + 1));
	if (!env_tab)
		ft_exit(ERRMEMALLOC, data, 2);
	i = 0;
	while (i < data->nb_env)
	{
		ft_putstr_fd("", 1);
		env_tab[i].name = data->env[i].name;
		env_tab[i].content = data->env[i].content;
		i++;
	}
	env_tab[i].name = name;
	env_tab[i].content = content;
	free(data->env);
	data->env = env_tab;
	data->nb_env++;
}

void	update_val_env(t_data *data, char *name, char *new_content)
{
	int		i;

	i = 0;
	while (i < data->nb_env
		&& ft_strnncmp(data->env[i].name, name, ft_strlen(name)) != 0)
		i++;
	if (i != data->nb_env
		&& ft_strnncmp(data->env[i].name, name, ft_strlen(name)) == 0)
	{
		free(data->env[i].content);
		data->env[i].content = new_content;
	}
	else
		new_env(data, name, new_content);
	free(name);
}

void	del_env_bis(t_data *data, char *name, t_list_env *env_tmp)
{
	free(data->env);
	free(name);
	data->env = env_tmp;
	data->nb_env--;
}

void	del_env(t_data *data, char *name)
{
	t_list_env	*env_tmp;
	int			i;
	int			j;

	env_tmp = malloc(sizeof(t_list_env) * (data->nb_env - 1));
	if (!env_tmp)
		ft_exit(ERRMEMALLOC, data, 2);
	i = 0;
	j = 0;
	while (i < data->nb_env)
	{
		if (ft_strnncmp(data->env[i].name, name, ft_strlen(name)) != 0)
		{
			env_tmp[j].name = data->env[i].name;
			env_tmp[j].content = data->env[i].content;
			j++;
		}
		else
		{
			free(data->env[i].name);
			free(data->env[i].content);
		}
		i++;
	}
	del_env_bis(data, name, env_tmp);
}
