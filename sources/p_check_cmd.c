/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:42:55 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/28 23:42:55 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_cmd_and(t_data *data, int val)
{
	int	i;

	i = 0;
	while (data->cmd[val].cmd[i] != '\0')
	{
		if (data->cmd[val].cmd[i] == '&' && data->cmd[val].cmd[i + 1] != '&')
		{
			data->err_nbr = 2;
			ft_printf(1, "minishell: syntax error near unexpected token `&'\n");
			data->cmd[val].cmd[0] = '\0';
			return ;
		}
		if (data->cmd[val].cmd[i] == '&' && data->cmd[val].cmd[i + 1] == '&')
		{
			data->err_nbr = 2;
			ft_printf(1, "minishell: syntax error near unexpected token `&&'\n");
			data->cmd[val].cmd[0] = '\0';
			return ;
		}
		i++;
	}
}

void	check_cmd_semicolon(t_data *data, int val)
{
	int	i;

	i = 0;
	while (data->cmd[val].cmd[i] != '\0')
	{
		if (data->cmd[val].cmd[i] == ';' && data->cmd[val].cmd[i + 1] != ';')
		{
			data->err_nbr = 2;
			ft_printf(1, "minishell: syntax error near unexpected token `;'\n");
			data->cmd[val].cmd[0] = '\0';
			return ;
		}
		if (data->cmd[val].cmd[i] == ';' && data->cmd[val].cmd[i + 1] == ';')
		{
			data->err_nbr = 2;
			ft_printf(1, "minishell: syntax error near unexpected token `;;'\n");
			data->cmd[val].cmd[0] = '\0';
			return ;
		}
		i++;
	}
}

void	check_cmd_dot(t_data *data, int val)
{
	if (data->cmd[val].cmd[0] == '.' && data->cmd[val].cmd[1] == '\0')
	{
		data->err_nbr = 2;
		ft_printf(1, "minishell: .: filename argument required\n.: \
			usage: . filename [arguments]\n");
		data->cmd[val].cmd[0] = '\0';
	}
	if (data->cmd[val].cmd[0] == '.' && data->cmd[val].cmd[1] == '.' \
		&& data->cmd[val].cmd[2] == '\0')
	{
		data->err_nbr = 2;
		ft_printf(1, "minishell: ..: command not found\n");
		data->cmd[val].cmd[0] = '\0';
	}
}

void	check_cmd(t_data *data, int val)
{
	if ((data->cmd[val].cmd[0] == ':' || data->cmd[val].cmd[0] == '#') \
		&& data->cmd[val].cmd[1] == '\0')
		data->cmd[val].cmd[0] = '\0';
	if (data->cmd[val].cmd[0] == '!' && data->cmd[val].cmd[1] == '\0')
	{
		data->err_nbr = 1;
		data->cmd[val].cmd[0] = '\0';
	}
	check_cmd_slash(data, val);
	check_cmd_and(data, val);
	check_cmd_semicolon(data, val);
	check_cmd_dot(data, val);
}
