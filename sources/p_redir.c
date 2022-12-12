/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_redir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:57:52 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/12 13:39:21 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_nb_redir_bis(char *str, int i)
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

int	get_nb_redir(t_data *data, int val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->cmd[val]._cmd[i] != '\0')
	{
		i = get_nb_redir_bis(data->cmd[val]._cmd, i);
		if (data->cmd[val]._cmd[i] == '<')
		{
			if (data->cmd[val]._cmd[i + 1] != '<')
				j++;
		}
		else if (data->cmd[val]._cmd[i] == '>')
		{
			if (data->cmd[val]._cmd[i + 1] != '>')
				j++;
		}
		if (data->cmd[val]._cmd[i] != '\0')
			i++;
	}
	return (j);
}

void	ft_remove_spaces_bis(t_data *data, int val, int i, char *str)
{
	int	j;
	int	flg;

	j = 0;
	flg = 0;
	while (data->cmd[val]._cmd[i] != '\0')
	{
		if (data->cmd[val]._cmd[i] == ' ' || data->cmd[val]._cmd[i] == '\t')
			flg = 1;
		if (!(data->cmd[val]._cmd[i] == ' ' || data->cmd[val]._cmd[i] == '\t'))
		{
			if (flg)
				str[j++] = ' ';
			flg = 0;
			str = cp_redir_quote(data->cmd[val]._cmd, str, &i, &j);
			str[j++] = data->cmd[val]._cmd[i];
		}
		if (data->cmd[val]._cmd[i] != '\0')
			i++;
	}
	str[j] = '\0';
	free(data->cmd[val]._cmd);
	data->cmd[val]._cmd = str;
}

void	ft_remove_spaces(t_data *data, int val)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = malloc(sizeof(char) * ft_strlen(data->cmd[val]._cmd) + 2);
	if (!str)
		ft_exit(ERRMEMALLOC, data, 2);
	while (data->cmd[val]._cmd[i] == ' ' || data->cmd[val]._cmd[i] == '\t')
		i++;
	ft_remove_spaces_bis(data, val, i, str);
}

void	get_redir(t_data *data, int val)
{
	int		i;

	i = 0;
	data->cmd[val].nb_redir = get_nb_redir(data, val);
	data->cmd[val].redirection = malloc(sizeof(char *)
			* data->cmd[val].nb_redir);
	if (!data->cmd[val].redirection)
		ft_exit(ERRMEMALLOC, data, 2);
	i = get_redir_bis(data, val, i);
	data->cmd[val]._cmd[i] = '\0';
	ft_remove_spaces(data, val);
}
