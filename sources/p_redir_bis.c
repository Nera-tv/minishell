/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_redir_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:14:02 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/09 14:22:46 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_redir_bis(t_data *data, int val, int i)
{
	char	*tmp;
	int		j;
	
	j = 0;
	while (data->cmd[val]._cmd[i] != '\0')
	{
		if (data->cmd[val]._cmd[i] == '<' || data->cmd[val]._cmd[i] == '>')
		{
			data->cmd[val].redirection[j] = cp_redir(data->cmd[val]._cmd, i, \
				data);
			tmp = ft_replace_word(data->cmd[val]._cmd,
					data->cmd[val].redirection[j++], "", data);
			free(data->cmd[val]._cmd);
			data->cmd[val]._cmd = tmp;
			printf("%s\n", data->cmd[val].redirection[j - 1]);
		}
		if (data->cmd[val]._cmd[i] != '\0')
			i++;
	}
	return (i);
}