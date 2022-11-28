/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:21:14 by tweidema          #+#    #+#             */
/*   Updated: 2022/11/28 14:29:32 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	opening_file_output(char *file_output, char *till_next, int fd)
{
	while (file_output)
	{
		if (fd)
		{
			if (close(fd) < 0)
				return (-1);
		}
		if (file_output[1] == '>')
		{
			till_next = realloc_till_char(file_output[1], '>', 0);
			till_next = realloc_till_char(till_next, ' ', 1);
			fd = open(till_next, O_CREAT | O_APPEND | O_WRONLY,
					S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
		}
		else
		{
			till_next = realloc_till_char(file_output[1], ' ', 0);
			fd = open(till_next, O_CREAT | O_TRUNC | O_WRONLY,
					S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
		}
		if (fd < 0)
			return (-1);
	}
	return (fd);
}

int	get_me_file_output(t_cmd *cmd)
{
	int		fd;
	size_t	i;
	char	*file_output;
	char	*till_next;

	i = 0;
	fd = 0;
	file_output = ft_strdup(ft_strchr(cmd->_cmd, '>'));
	if (!ft_strchr(cmd->_cmd, '>'))
		return (0);
	if (!file_output)
		return (-1);
	fd = opening_file_output(file_output, till_next, fd);
	if (fd < 0)
		return (-1);
	return (fd);
}
