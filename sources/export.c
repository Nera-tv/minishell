/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:57 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:31:11 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_name(char *arg)
{
	int		i;
	char	*name;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	name = ft_substr(arg, 0, i);
	return (name);
}

char	*get_content(char *arg)
{
	int		i;
	char	*content;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	if (arg[i] == '\0')
		return (NULL);
	content = ft_substr(arg, i + 1, ft_strlen(arg) - i);
	return (content);
}

int	check_name(t_data *data, char *name, char *content)
{
	int	i;

	i = 0;
	while (i < data->nb_env)
	{
		if (ft_strnncmp(data->env[i].name, name, ft_strlen(name)) == 0)
		{
			if (content != NULL)
				data->env[i].content = content;
			free(name);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_export(t_data *data, int val)
{
	int		i;
	int		nbr_args;
	char	*name;
	char	*content;

	if (!data->cmd[val]._args)
		ft_sort_and_print_env(data);
	else
	{
		i = 0;
		nbr_args = nb_args(data->cmd[val].args);
		while (i < nbr_args)
		{
			content = get_content(data->cmd[val].args[i]);
			name = get_name(data->cmd[val].args[i]);
			if (check_name(data, name, content) == 0)
				new_env(data, name, content);
			i++;
		}
	}
}
