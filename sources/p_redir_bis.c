/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_redir_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:14:02 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/12 13:01:33 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*cp_redir_quote(char *str, char *cp,  int *i, int *j)
{
	if (str[*i] == '\"')
	{
		cp[(*j)++] = str[(*i)++];
		while (str[*i] != '\"' && str[*i] != '\0')
			cp[(*j)++] = str[(*i)++];
	}
	if (str[*i] == '\'')
	{
		cp[(*j)++] = str[(*i)++];
		while (str[*i] != '\'' && str[*i] != '\0')
			cp[(*j)++] = str[(*i)++];
	}
	return (cp);
}

char	*cp_redir(char *str, int i, t_data *data)
{
	int		j;
	int		len;
	char	*ret;

	len = 0;
	ret = NULL;
	while (str[i + len] != ' ' && (str[i + len] == '>' || str[i + len] == '<'))
		len++;
	while (str[i + len] == ' ')
		len++;
	while (str[i + len] != ' ' && str[i + len] != '\0')
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		ft_exit(ERRMEMALLOC, data, 2);
	j = 0;
	while (j < len)
	{
		ret[j] = str[i + j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

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
					ft_strdup(data->cmd[val].redirection[j++]), "", data);
			free(data->cmd[val]._cmd);
			data->cmd[val]._cmd = tmp;
		}
		if (data->cmd[val]._cmd[i] != '\0')
			i++;
	}
	return (i);
}
