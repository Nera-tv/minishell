/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:19:48 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/07 14:28:47 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	opening_file_output(t_data *data, int val)
{
	int	fd;

	fd = 0;
	if (data->cmd[val].output_method == 0)
		return (0);
	if (data->cmd[val].output_method == 1)
	fd = open(data->cmd[val].file_output, O_CREAT | O_TRUNC | O_WRONLY,
				S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	else if (data->cmd[val].output_method == 2)
	fd = open(data->cmd[val].file_output, O_CREAT | O_APPEND | O_WRONLY,
				S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		ft_exit(ERRFD, data, 1);
	return (fd);
}
