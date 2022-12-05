/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:21:14 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/05 10:41:55 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	opening_file_output(char *file_output, char *till_next, int fd, t_data *d)
{
	while (file_output)
	{
		if (fd && close(fd) < 0)
			ft_exit(ERRFD, d, 1);
		while (file_output[1] == ' ')
			file_output = &file_output[1];
		if (file_output[1] == '>')
		{
			till_next = realloc_till_char(&file_output[1], '>', 0, d);
			till_next = realloc_till_char(till_next, ' ', 1, d);
			fd = open(till_next, O_CREAT | O_APPEND | O_WRONLY,
					S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
		}
		else
		{
			till_next = realloc_till_char(&file_output[1], ' ', 0, d);
			fd = open(till_next, O_CREAT | O_TRUNC | O_WRONLY,
					S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
		}
		if (fd < 0)
			ft_exit(ERRFD, d, 1);
		dprintf(2, "foutput = %s\n", file_output);
		file_output = ft_strchr(file_output, '>');
	}
	return (fd);
}

int	get_me_file_output(t_data *data, int val)
{
	int		fd;
	size_t	i;
	char	*file_output;
	char	*till_next;

	i = 0;
	fd = 1;
	till_next = NULL;
	dprintf(2, "Je suis ici %s\n", ft_strchr(data->cmd[val]._cmd, '>'));
	if (!ft_strchr(data->cmd[val]._cmd, '>'))
		return (0);
	file_output = ft_strdup(ft_strchr(data->cmd[val]._cmd, '>'));
	if (!file_output)
		return (-1); //Erreur de si la personne essaie d'ouvrir un fichier qui n'a pas de nom
	fd = opening_file_output(file_output, till_next, fd, data);
	if (file_output)
		free(file_output);
	return (fd);
}
