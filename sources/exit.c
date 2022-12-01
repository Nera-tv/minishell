/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:17:14 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/01 10:09:59 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	if_str_or_nbr(char *args)
{
	int	i;

	i = 0;
	while (args[i] != '\0')
	{
		if (ft_isdigit(args[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

void	exit_if_blt_exit(t_data *data, int val)
{
	int	err_val;

	err_val = 0;
	ft_printf(2, "exit\n");
	if (data->cmd[val].nbr_args == 0)
		ft_exit(NULL, data, 0);
	else if (data->cmd[val].nbr_args > 1)
	{
		if (if_str_or_nbr(data->cmd[val].args[0]) == 0)
		{
			data->err_nbr = 1;
			ft_printf(1, "bash: exit: too many arguments\n");
		}
		else
		{
			ft_printf(1, "bash: exit: %s: numeric argument required\n", data->cmd[val].args[0]);
			ft_exit(NULL, data, 2);
		}
	}
	else if (data->cmd[val].nbr_args == 1)
	{
		if (if_str_or_nbr(data->cmd[val].args[0]) == 0)
		{
			err_val = ft_atoi(data->cmd[val].args[0]);
			if (err_val > 256)
				ft_exit(NULL, data, (err_val - 256));
			else
				ft_exit(NULL, data, err_val);
		}
		else
		{
			ft_printf(1, "bash: exit: %s: numeric argument required\n", data->cmd[val].args[0]);
			ft_exit(NULL, data, 2);
		}
	}
}

void	ft_exit(char *msg, t_data *data, int err_nbr)
{
	int	j;

	ft_printf(2, msg);
	free(data->line);
	free(data->pwd);
	j = 0;
	if (data->indic_first_cd == 1)
	{
		while (j < data->nb_env)
		{
			free(data->env[j].content);
			j++;
		}
	}
	exit(err_nbr);
}
