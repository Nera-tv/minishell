/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_cmd_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:49:24 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/01 14:56:41 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//pb avec les points
void	check_cmd_slash_bis(t_data *data, int val)
{
	char	*pathok;
	char	*tmp;

	tmp = ft_strdup(data->cmd[val].cmd);
	pathok = access_check(tmp, data->path, data);
	if (!pathok)
	{
		data->err_nbr = 126;
		ft_printf(1, "minishell: %s: No such file or directory\n", \
			data->cmd[val].cmd);
		data->cmd[val].cmd[0] = '\0';
	}
	else
		free(pathok);
}

void	check_cmd_slash(t_data *data, int val)
{
	int	i;

	i = 0;
	if (data->cmd[val].cmd[0] == '/')
	{
		while (data->cmd[val].cmd[i] != '\0')
		{
			if (data->cmd[val].cmd[i] != '/')
			{
				check_cmd_slash_bis(data, val);
				return ;
			}
			i++;
		}
		data->err_nbr = 126;
		ft_printf(1, "minishell: %s: Is a directory\n", data->cmd[val].cmd);
		data->cmd[val].cmd[0] = '\0';
	}
}
