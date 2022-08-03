/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neress <neress@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:50:00 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/03 07:49:01 by neress           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_strnncmp(data->envp[i], "PWD=", ft_strlen("PWD=")) == 0)
		{
			ft_putstr_fd(data->envp[i], 1);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
}
