/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_cmd_arg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:40 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/12 13:35:55 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	if_only_space(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] != '\0')
	{
		if (data->line[i] != ' ')
		{
			data->only_spaces = 0;
			return (1);
		}
		i++;
	}
	data->only_spaces = 1;
	return (0);
}

int	check_line_pipe_bis_bis(t_data *data, int i)
{
	i++;
	while (data->line[i] == ' ')
		i++;
	if (data->line[i] == '|')
	{
		data->err_nbr = 2;
		if (data->line[i - 1] != '|')
		{
			data->err_msg = \
			"minishell: syntax error near unexpected token `|'\n";
		}
		else
		{
			data->err_msg = \
			"minishell: syntax error near unexpected token `||'\n";
		}
		return (-1);
	}
	return (i);
}

int	check_line_pipe_bis(t_data *data, int i)
{
	if (data->line[i] == '\"')
	{
		i++;
		while (data->line[i] != '\"' && data->line[i] != '\0')
			i++;
	}
	else if (data->line[i] == '\'')
	{
		i++;
		while (data->line[i] != '\'' && data->line[i] != '\0')
			i++;
	}
	else if (data->line[i] == '|')
		return (check_line_pipe_bis_bis(data, i));
	return (i);
}

int	check_line_pipe(t_data *data)
{
	int	i;

	i = 0;
	if (data->line[i] == '\0')
		return (1);
	while (data->line[i] == ' ')
		i++;
	if (data->line[i] == '|' && data->line[i + 1] != '|')
	{
		return (ret_error_pipe_parse(data, \
			"minishell: syntax error near unexpected token `|'\n"));
	}
	while (data->line[i] != '\0')
	{
		i = check_line_pipe_bis(data, i);
		if (i == -1)
			return (1);
		if (data->line[i] != '\0')
			i++;
	}
	i = check_line_pipe_go_back(data, i);
	if (i == -1)
		return (1);
	return (0);
}

void	get_nbr_cmd(t_data *data)
{
	int	i;

	data->nbr_cmds++;
	i = 0;
	while (data->line[i] != '\0')
	{
		if (data->line[i] == '\"')
		{
			i++;
			while (data->line[i] != '\"' && data->line[i] != '\0')
				i++;
		}
		else if (data->line[i] == '\'')
		{
			i++;
			while (data->line[i] != '\'' && data->line[i] != '\0')
				i++;
		}
		else if (data->line[i] == '|')
			data->nbr_cmds++;
		if (data->line[i] != '\0')
			i++;
	}
}
