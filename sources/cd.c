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
	printf("hello");
	while (data->env[i].name)
	{
		i++;
	}
}

void	ft_cd(t_data *data, int val)
{
	int	i;
	
	if (data->cmd[val]._args)
	{
		
	}
	else
	{
		i = 0;
		while (i < data->nb_env)
		{
			if (ft_strnncmp(data->env[i].name, "HOME", ft_strlen("HOME")) == 0)
				change_dir(data, data->env[i].content);
			i++;
		}
	}
}





















/*
char	*get_home_bis(t_data *data, int j, int i, char *home_tmp[2])
{
	int	len;
	int	k;

	len = 0;
	while (data->envp[i][j + len] != '\0')
	{
		home_tmp[0][len] = data->envp[i][j + len];
		len++;
	}
	j = 0;
	k = 1;
	while (home_tmp[1][k] != '\0')
	{
		home_tmp[0][len + j] = home_tmp[1][k];
		j++;
		k++;
	}
	home_tmp[0][len + j] = '\0';
	return (home_tmp[0]);
}

char	*get_home(t_data *data, int val, int i)
{
	int		j;
	int		len;
	char	*home_tmp[2];

	j = 0;
	len = 0;
	while (data->envp[i][j] != '=')
		j++;
	j++;
	while (data->envp[i][j + len] != '\0')
		len++;
	home_tmp[1] = data->cmd[val]._args;
	home_tmp[0] = malloc(sizeof(char)
			* (len + ft_strlen(data->cmd[val]._args) + 1));
	home_tmp[0] = get_home_bis(data, j, i, home_tmp);
	return (home_tmp[0]);
}

int	check_if_tilde(t_data *data, int val)
{
	char	*tmp;
	int		i;

	if (data->cmd[val]._args[0] == '~')
	{
		i = 0;
		while (data->envp[i])
		{
			if (ft_strnncmp(data->envp[i], "OLDPWD=", ft_strlen("OLDPWD=")) == 0)
			{
				tmp = get_home(data, val, i);
				change_dir(data, tmp);
				free(tmp);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

char	*get_home_no_arg(t_data *data, int i)
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

void	ft_cd(t_data *data, int val)
{
	char	*tmp;
	int		i;

	if (data->cmd[val]._args)
	{
		check_arg(data, val);
		if (check_if_tilde(data, val) == 0 && check_if_dash(data, val) == 0)
			change_dir(data, data->cmd[val]._args);
	}
	else
	{
		i = 0;
		while (data->envp[i])
		{
			if (ft_strnncmp(data->envp[i], "HOME=", ft_strlen("HOME=")) == 0)
			{
				tmp = get_home_no_arg(data, i);
				change_dir(data, tmp);
				free(tmp);
			}
			i++;
		}
	}
}*/
