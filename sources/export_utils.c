/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:09:09 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:30:13 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp_export(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (((unsigned char) *s1 - (unsigned char) *s2) > 0)
		return (1);
	else if (((unsigned char) *s1 - (unsigned char) *s2) < 0)
		return (-1);
	return (0);
}

void	ft_swap_env(t_list_env *a, t_list_env *b)
{
	t_list_env	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_print_sorted_env(t_list_env	*env, int nb_env)
{
	int	i;

	i = 0;
	while (i < nb_env)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env[i].name, 1);
		if (env[i].content)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env[i].content, 1);
			ft_putchar_fd('\"', 1);
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}

t_list_env	*cp_list_env(t_data *data)
{
	t_list_env	*envcp;
	int			i;

	envcp = malloc(sizeof(t_list_env) * (data->nb_env + 1));
	if (!envcp)
		ft_exit(ERRMEMALLOC, data);
	i = 0;
	while (i < data->nb_env)
	{
		envcp[i].name = data->env[i].name;
		envcp[i].content = data->env[i].content;
		i++;
	}
	return (envcp);
}

void	ft_sort_and_print_env(t_data *data)
{
	int			i;
	int			j;
	t_list_env	*envcp;

	i = 0;
	envcp = cp_list_env(data);
	while (i++ < data->nb_env)
	{
		j = i + 1;
		while (j < data->nb_env)
		{
			if (ft_strcmp_export(envcp[i].name, envcp[j].name) == 1)
				ft_swap_env(&envcp[i], &envcp[j]);
			j++;
		}
	}
	ft_print_sorted_env(envcp, data->nb_env);
	free (envcp);
}
