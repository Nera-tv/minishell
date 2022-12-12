/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_line_lt_gt_bis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:38:12 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/12 10:40:42 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ret_check_redir(t_data *data, char *msg, int err_nb)
{
	data->err_msg = msg;
	data->err_nbr = err_nb;
	return (1);
}

int	check_line_redir_quater(t_data *data, int i)
{
	if (data->line[i] == '>' && (data->line[i + 1] == '<'
			|| data->line[i + 1] == '>') && (data->line[i + 2] == '<'
			|| data->line[i + 2] == '>'))
		return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `>'\n", 2));
	if (data->line[i] == '>')
	{
		i++;
		while (data->line[i] == ' ')
			i++;
		if (data->line[i] == '>' || data->line[i] == '<')
			return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `>'\n", 2));
	}
	if (data->line[i] == '<')
	{
		i++;
		while (data->line[i] == ' ')
			i++;
		if (data->line[i] == '>' || data->line[i] == '<')
			return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `<'\n", 2));
	}
	return (0);
}
