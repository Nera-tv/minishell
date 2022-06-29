/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:53:26 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/22 13:59:11 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_nbr_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmdl[i] != '\0')
	{
		if (data->cmdl[i] == '|')
		{
			data->exec.nb_cmd++;
			i++;
		}
		i++;
	}
}

void	read_line(const char *prompt, t_data *data)
{
	data->cmdl = readline(prompt);
	if (data->cmdl != NULL
		&& ft_strncmp(data->cmdl, "exit", ft_strlen("exit")) == 0)
		ft_exit("exit\n", data);
	if (data->cmdl == NULL)
		ft_exit("exit\n", data);
	get_cmd_arg(data);
	if (ft_strncmp(data->cmdl, "\0", ft_strlen("\0") == 0))
		ft_printf(2, ERRCMD, data->cmdl);
	data->p_cmd.nbr_args = 0;
	free(data->cmdl);
}
