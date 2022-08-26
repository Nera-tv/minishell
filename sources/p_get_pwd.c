/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 23:43:45 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 01:25:05 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_value_pwd(t_data *data, int i, int j, int k)
{
	int	v;

	data->pwd = malloc(sizeof(char *) * (k + 1));
	if (data->pwd == NULL)
		ft_exit("allocation error", data);
	v = 0;
	while (data->envp[i][j + v] != '\0')
	{
		data->pwd[v] = data->envp[i][j + v];
		v++;
	}
	data->pwd[v] = '\0';
}

void	get_pwd(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (data->envp[i])
	{
		if (ft_strnncmp(data->envp[i], "PWD=", ft_strlen("PWD=")) == 0)
		{
			while (data->envp[i][j] != '=')
				j++;
			j++;
			while (data->envp[i][j + k] != '\0')
				k++;
			set_value_pwd(data, i, j, k);
		}
		i++;
	}
}
