/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:36:56 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/08 13:28:42 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_arg(t_data *data, int val)
{
	int	i;

	i = 0;
	while (data->cmd[val]._args[i] != '\0')
	{
		i++;
		if (data->cmd[val]._args[i] == ' '
			&& (data->cmd[val]._args[i + 1] == ' '
				|| data->cmd[val]._args[i + 1] == '\0'))
			data->cmd[val]._args[i] = '\0';
	}
}

void	change_dir(t_data *data, char *path)
{
	int	i;

	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 1);
		ft_putstr_fd(path, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
	}
	getcwd(data->pwd, ft_strlen(data->pwd) + ft_strlen(path) + 2);
	i = 0;
	while (data->env[i].name)
	{
		if (ft_strnncmp(data->env[i].name, "PWD", ft_strlen("PWD")) == 0)
		{
			if (data->indic_first_cd == 1 && data->envp[i])
				free (data->envp[i]);
			data->envp[i] = ft_strjoin("PWD=", data->pwd);
			data->indic_first_cd = 1;
		}
		i++;
	}
}
