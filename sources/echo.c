/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:55:31 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/10 13:11:37 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	nb_args(char **args)
{
	int		size;

	size = 0;
	if (args)
	{
		while (args[size])
			size++;
		return (size);
	}
	return (0);
}

int	check_dash_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' && arg[i + 1] == 'n')
	{
		i++;
		while (arg[i] != '\0')
		{
			if (arg[i] != 'n')
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

void	ft_echo(t_data *data, int val)
{
	int		i;
	int		n_option;

	i = 0;
	n_option = 0;
	if (data->cmd[val]._args != NULL && nb_args(data->cmd[val].args) >= 1)
	{
		while (data->cmd[val].args[i]
			&& check_dash_n(data->cmd[val].args[i]) == 1)
		{
			n_option = 1;
			i++;
		}
		while (data->cmd[val].args[i])
		{
			ft_putstr_fd(data->cmd[val].args[i], 1);
			if (data->cmd[val].args[i + 1] && data->cmd[val].args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	data->err_nbr = 0;
}
