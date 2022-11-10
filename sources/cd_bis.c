/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:17 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:49:06 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_oldpwd(t_data *data, int i)
{
	char	*tmp;
	int		j;
	int		len;

	j = 0;
	while (data->envp[i][j] != '=')
		j++;
	j++;
	len = 0;
	while (data->envp[i][j + len] != '\0')
		len++;
	tmp = malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (data->envp[i][j + len] != '\0')
	{
		tmp[len] = data->envp[i][j + len];
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}

int	check_if_dash(t_data *data, int val)
{
	char	*tmp;
	int		i;

	if (data->cmd[val]._args[0] == '-')
	{
		i = 0;
		while (data->envp[i])
		{
			if (ft_strnncmp(data->envp[i], "HOME=", ft_strlen("HOME=")) == 0)
			{
				tmp = get_oldpwd(data, i);
				change_dir(data, tmp);
				free(tmp);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
