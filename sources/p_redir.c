/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_redir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:57:52 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/10 18:01:43 by tweidema         ###   ########.fr       */
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

void	ft_remove_spaces_bis(t_data *data, int val, int i, char *str)
{
	int	j;
	int	flg;

	j = 0;
	flg = 0;
	while (data->cmd[val]._cmd[i])
	{
		if (data->cmd[val]._cmd[i] == ' ' || data->cmd[val]._cmd[i] == '\t')
			flg = 1;
		if (!(data->cmd[val]._cmd[i] == ' ' || data->cmd[val]._cmd[i] == '\t'))
		{
			if (flg)
				str[j++] = ' ';
			flg = 0;
			str[j++] = data->cmd[val]._cmd[i];
		}
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
	str = malloc(sizeof(char) * ft_strlen(data->cmd[val]._cmd) + 1);
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
	dprintf(2, "Data redir = --%s--\n", data->cmd[val].redirection[0]);
	ft_remove_spaces(data, val);
}
