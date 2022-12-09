/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_cmd_arg_utils_bis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:19:55 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/09 13:55:33 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_line_pipe_go_back(t_data *data, int i)
{
	i--;
	while (data->line[i] == ' ')
		i--;
	if (data->line[i] == '|')
	{
		ret_error_pipe_parse(data, \
		"minishell: syntax error: unexpected end of file\n");
		return (-1);
	}
	return (i);
}

int	ret_error_pipe_parse(t_data *data, char *msg)
{
	data->err_nbr = 2;
	data->err_msg = msg;
	return (1);
}
