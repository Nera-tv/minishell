/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:38:14 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/22 14:50:01 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	access_check(t_data *data, int which_cmd)
{
	int		i;
	char	*ret;

	i = 0;
	if (!access(data->cmd[which_cmd][0], R_OK))
		return (0);
	while (i < data->nb_env)
	{
		ret = ft_strslasj(data->path[i], data->cmd[which_cmd][0]);
		if (!ret)
			ft_exit(strerror(errno), data);
		if (!access(ret, X_OK))
		{
			free(data->cmd[which_cmd][0]);
			return (0);
		}
		free(ret);
		i++;
	}
	free(data->cmd[which_cmd][0]);
	return (1);
}
