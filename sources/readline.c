/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchin <apouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:22:21 by apouchin          #+#    #+#             */
/*   Updated: 2022/07/13 12:22:33 by apouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	read_line(const char *prompt, t_data *data)
{
	data->cmdl = readline(prompt);
	if (data->cmdl != NULL && ft_strncmp(data->cmdl, "exit", ft_strlen("exit")) == 0)
		ft_exit("exit\n", data);
	if (data->cmdl == NULL)
		ft_exit("exit\n", data);
	get_cmd_arg(data);
	free(data->cmdl);
}
