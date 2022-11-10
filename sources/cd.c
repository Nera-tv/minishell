/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:50 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/08 13:27:51 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_oldpwd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_env)
	{
		if (ft_strnncmp(data->env[i].name, "OLDPWD", ft_strlen("OLDPWD")) == 0)
		{
			free(data->env[i].content);
			data->env[i].content = ft_strdup(data->pwd);
			return ;
		}
		i++;
	}
}

int	change_dir_bis(t_data *data, int i)
{
	if (ft_strnncmp(data->env[i].name, "PWD", ft_strlen("PWD")) == 0)
	{
		free (data->env[i].content);
		data->env[i].content = ft_strdup(data->pwd);
		return (1);
	}
	return (0);
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
	else
	{
		set_oldpwd(data);
		getcwd(data->pwd, ft_strlen(data->pwd) + ft_strlen(path) + 2);
		i = 0;
		while (i < data->nb_env)
		{
			if (change_dir_bis(data, i) == 1)
				return ;
			i++;
		}
	}
}

void	ft_cd(t_data *data, int val)
{
	int	i;

	if (data->cmd[val]._args)
	{
		if (check_if_tilde(data, val) == 0 && check_if_dash(data, val) == 0)
			change_dir(data, data->cmd[val]._args);
		i = 0;
	}
	else
	{
		i = 0;
		while (i < data->nb_env)
		{
			if (ft_strnncmp(data->env[i].name, "HOME", ft_strlen("HOME")) == 0)
			{
				if (data->env[i].content)
					change_dir(data, data->env[i].content);
				else
					ft_putstr_fd("minishell: cd: HOME not set\n", 1);
			}
			i++;
		}
	}
}
