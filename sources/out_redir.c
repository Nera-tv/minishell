/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:21:14 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/10 14:37:25 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	if_trunc(char *file_output, t_data *data, int val)
{
	char	*till_next;
	int		fd;

	till_next = skip_this_char(&file_output[1], ' ');
	till_next = realloc_till_char(till_next, ' ', 0, data);
	fd = open(till_next, O_CREAT | O_TRUNC | O_WRONLY,
			S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	if (close(fd) < 0)
	{
		free (till_next);
		return ;
	}
	data->cmd[val].file_output = till_next;
	data->cmd[val].output_method = 1;
}

void	if_append(char *file_output, t_data *data, int val)
{
	int		fd;
	char	*till_next;

	till_next = skip_this_char(&file_output[2], ' ');
	till_next = realloc_till_char(till_next, ' ', 0, data);
	fd = open(till_next, O_CREAT | O_APPEND | O_WRONLY,
			S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	if (close(fd) < 0)
	{
		free (till_next);
		return ;
	}
	data->cmd[val].file_output = till_next;
	data->cmd[val].output_method = 2;
}

int	storing_file_output(char **file_output, t_data *d, int val)
{
	int	i;

	i = 0;
	while (i < d->cmd[val].nb_redir)
	{
		if (file_output[i][0] == '>' && file_output[i][1] == '>')
			if_append(file_output[i], d, val);
		else if (file_output[i][0] == '>')
			if_trunc(file_output[i], d, val);
		i++;
	}
	return (0);
}

int	get_me_file_redirect(t_data *data, int val)
{
	if (data->cmd[val].nb_redir == 0)
		return (0);
	storing_file_output(data->cmd[val].redirection, data, val);
	storing_file_input(data->cmd[val].redirection, data, val);
	return (0);
}
