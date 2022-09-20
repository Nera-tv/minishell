/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:09:00 by dvilard           #+#    #+#             */
/*   Updated: 2022/09/20 17:53:38 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_cmd_len_bis(char *line, int len)
{
	if (line[len] == '\"')
	{
		len++;
		while (line[len] != '\0' && line[len] != '\"')
		{
			if (line[len] == '\\' && line[len + 1] == '\"')
				len += 2;
			len++;
		}
	}
	else if (line[len] == '\'')
	{
		len++;
		while (line[len] != '\0' && line[len] != '\'')
			len++;
	}
	return (len);
}

int	get_cmd_len(t_data *data, int val)
{
	int		len;
	char	*line;

	len = 0;
	line = data->cmd[val]._cmd;
	while (line[len] != '\0' && line[len] != ' ')
	{
		if (line[len] != '\\')
			len = get_cmd_len_bis(line, len);
		else
		{
			if (line[len + 1] == '\"' || line[len + 1] == '\'')
				len += 2;
		}
		if (line[len] != '\0' && line[len] != ' ')
			len++;
	}
	return (len);
}
