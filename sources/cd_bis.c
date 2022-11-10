/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:17 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:49:06 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_if_dash_bis(t_data *data, int i)
{
	char	*tmp;

	if (ft_strnncmp(data->env[i].name,
			"OLDPWD", ft_strlen("OLDPWD")) == 0)
	{
		if (data->env[i].content)
		{
			tmp = ft_strdup(data->env[i].content);
			change_dir(data, tmp);
			free(tmp);
		}
		else
		{
			ft_putstr_fd(data->pwd, 1);
			ft_putchar_fd('\n', 1);
		}
		return (1);
	}
	return (0);
}

int	check_if_dash(t_data *data, int val)
{
	int		i;

	if (data->cmd[val]._args[0] == '-')
	{
		i = 0;
		while (i < data->nb_env)
		{
			if (check_if_dash_bis(data, i) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}

int	check_if_tilde(t_data *data, int val)
{
	int		i;

	if (data->cmd[val]._args[0] == '~')
	{
		i = 0;
		while (i < data->nb_env)
		{
			if (ft_strnncmp(data->env[i].name, "HOME", ft_strlen("HOME")) == 0)
			{
				if (data->env[i].content)
					change_dir(data, data->env[i].content);
				else
					ft_putstr_fd("\n", 1);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
