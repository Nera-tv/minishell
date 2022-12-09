/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_line_lt_gt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:16 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/09 17:21:10 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ret_check_redir(t_data *data, char *msg)
{
	data->err_msg = msg;
	return (1);
}

int	check_line_redir_bis_bis(t_data *data, int i)
{
	if (data->line[i] == '>' && data->line[i + 1] == '<')
		return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `<'\n"));
	if (data->line[i] == '<' && data->line[i + 1] == '>')
		return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `>'\n"));
	if ((data->line[i] == '<' || data->line[i] == '>') \
		&& (data->line[i + 1] == '<' || data->line[i + 1] == '>') \
		&& (data->line[i + 2] == '<' || data->line[i + 2] == '>'))
		return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `<'\n"));
	if (data->line[i] == '<' && data->line[i + 1] == '<' \
		&& data->line[i + 2] == '<')
		return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `>'\n"));
	if (data->line[i] == '>' && data->line[i + 1] == '>' \
		&& data->line[i + 2] == '>')
		return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `>'\n"));
	return (0);
}

int	ret_end_check_line_redir_bis(t_data *data, int i)
{
	if (data->line[i + 1] == '\0' || data->line[i + 1] == '|'
		|| data->line[i + 1] == ' ')
	{
		i++;
		while (data->line[i] == ' ')
			i++;
		if (data->line[i] == '\0')
			return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `newline'\n"));
		else if (data->line[i] == '|' && data->line[i + 1] != '|' )
			return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `|'\n"));
		else if (data->line[i] == '|' && data->line[i + 1] == '|' )
			return (ret_check_redir(data, \
				"minishell: syntax error near unexpected token `||'\n"));
	}
	return (0);
}

int	check_line_redir_bis(t_data *data, int i)
{
	if (ret_end_check_line_redir_bis(data, i) == 1)
		return (1);
	if (data->line[i] == '>' && data->line[i + 1] == '>' \
		&& data->line[i + 2] != '>')
	{
		i++;
		if (ret_end_check_line_redir_bis(data, i) == 1)
			return (1);
	}
	else if (data->line[i] == '<' && data->line[i + 1] == '<' \
		&& data->line[i + 2] != '<')
	{
		i++;
		if (ret_end_check_line_redir_bis(data, i) == 1)
			return (1);
	}
	if (check_line_redir_bis_bis(data, i) == 1)
		return (1);
	return (0);
}

int	check_line_redir_quote(t_data *data, int i)
{
	if (data->line[i] == '\"')
	{
		i++;
		while (data->line[i] != '\"' && data->line[i] != '\0' \
			&& data->line[i] != '|')
			i++;
	}
	if (data->line[i] == '\'')
	{
		i++;
		while (data->line[i] != '\'' && data->line[i] != '\0' \
			&& data->line[i] != '|')
			i++;
	}
	return (i);
}

int	check_line_redir(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] == ' ')
		i++;
	if (data->line[i] == '|' && data->line[i + 1] != '|')
		return (ret_check_redir(data, \
			"minishell: syntax error near unexpected token `|'\n"));
	if (data->line[i] == '|' && data->line[i + 1] == '|')
		return (ret_check_redir(data, \
			"minishell: syntax error near unexpected token `||'\n"));
	while (data->line[i] != '<' && data->line[i] != '>'
		&& data->line[i] != '\0')
	{
		i = check_line_redir_quote(data, i);
		if (data->line[i] != '\0')
			i++;
	}
	if (data->line[i] == '<' || data->line[i] == '>')
		return (check_line_redir_bis(data, i));
	return (0);
}
