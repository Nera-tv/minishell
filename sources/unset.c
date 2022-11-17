/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:50:04 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/17 14:00:14 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_name_unset(char *arg)
{
	int		i;
	char	*name;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd("\': not a valid identifier\n", 2);
			return (NULL);
		}
		i++;
	}
	name = ft_substr(arg, 0, i);
	return (name);
}

void	ft_unset(t_data *data, int val)
{
	int		i;
	int		nbr_args;
	char	*name;

	if (data->cmd[val].args)
	{
		i = 0;
		nbr_args = nb_args(data->cmd[val].args);
		while (i < nbr_args)
		{
			name = get_name_unset(data->cmd[val].args[i]);
			if (name)
				del_env(data, name);
			i++;
		}
	}
}
