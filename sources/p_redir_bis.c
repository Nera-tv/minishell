/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_redir_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:14:02 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/09 17:22:50 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_redir_bis_quote(char *str, int i)
{
	if (str[i] == '\"')
	{
		i++;
		while (str[i] != '\"' && str[i] != '\0')
			i++;
	}
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'' && str[i] != '\0')
			i++;
	}
	return (i);
}

int	get_redir_bis(t_data *data, int val, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	while (data->cmd[val]._cmd[i] != '\0')
	{
		i = get_redir_bis_quote(data->cmd[val]._cmd, i);
		if (data->cmd[val]._cmd[i] == '<' || data->cmd[val]._cmd[i] == '>')
		{
			data->cmd[val].redirection[j] = cp_redir(data->cmd[val]._cmd, i, \
				data);
			tmp = ft_replace_word(data->cmd[val]._cmd,
					data->cmd[val].redirection[j++], "", data);
			free(data->cmd[val]._cmd);
			data->cmd[val]._cmd = tmp;
		}
		if (data->cmd[val]._cmd[i] != '\0')
			i++;
	}
	return (i);
}
