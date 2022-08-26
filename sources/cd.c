/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:50 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 01:24:35 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_data *data, int val)
{
	printf("%s\n", data->pwd);
	if (data->cmd[val]._args)
	{
		if (chdir(data->cmd[val]._args) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 1);
			ft_putstr_fd(data->cmd[val]._args, 1);
			ft_putstr_fd(": No such file or directory\n", 1);
		}
		getcwd(data->pwd, ft_strlen(data->pwd)
			+ ft_strlen(data->cmd[val]._args) + 2);
	}
	printf("%s\n", data->pwd);
}
