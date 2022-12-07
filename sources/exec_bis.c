/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:21:14 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/07 14:00:54 by tweidema         ###   ########.fr       */
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
		ft_exit(ERRFD, data, 1);
	data->cmd[val].file_output = till_next;
	data->cmd[val].output_method = 1;
}

void	if_append(char *file_output, t_data *data, int val)
{
	int		fd;
	char	*till_next;

	till_next = skip_this_char(&file_output[2], ' ');
	till_next = realloc_till_char(till_next, ' ', 0, data);
	file_output = &file_output[1];
	fd = open(till_next, O_CREAT | O_APPEND | O_WRONLY,
			S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	if (close(fd) < 0)
		ft_exit(ERRFD, data, 1);
	data->cmd[val].file_output = till_next;
	data->cmd[val].output_method = 2;
}

int	opening_file_output(char *file_output, t_data *d, int val)
{
	while (file_output)
	{
		file_output = skip_this_char(file_output, ' ');
		if (file_output[1] == '>')
			if_append(file_output, d, val);
		else
			if_trunc(file_output, d, val);
		file_output = ft_strchr(&file_output[1], '>');
	}
	return (0);
}

int	get_me_file_output(t_data *data, int val)
{
	size_t	i;
	char	*file_output;

	i = 0;
	if (!ft_strchr(data->cmd[val]._cmd, '>'))
		return (0);
	file_output = ft_strdup(ft_strchr(data->cmd[val]._cmd, '>'));
	if (!file_output)
		return (-1); //Erreur de si la personne essaie d'ouvrir un fichier qui n'a pas de nom
	opening_file_output(file_output, data, val);
	if (file_output)
		free(file_output);
	return (0);
}
