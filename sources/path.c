/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:48:30 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/10 17:39:52 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fill_cmd_path(t_data *data, int val)
{
	int	i;

	i = 0;
	while (i < data->cmd[val].nbr_args + 2)
	{
		data->cmd[val].cmd_path[i] = NULL;
		i++;
	}
}

void	fill_arg_path(t_data *data, int val)
{
	int	i;

	i = 1;
	while (i < data->cmd[val].nbr_args + 1)
	{
		//printf("%s\n", data->cmd[val].args[i - 1]);
		data->cmd[val].cmd_path[i] = data->cmd[val].args[i - 1];
		i++;
	}
}

static char	*extract_exec(t_data *data, int val)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strchr(data->cmd[val].cmd, '/') != NULL || !data->path)
		return (data->cmd[val].cmd);
	while (data->path[i])
	{
		tmp = ft_strcjoin(data->path[i], data->cmd[val].cmd, '/');
		if (tmp)
		{
			if (access(tmp, X_OK) == 0)
				return (tmp);
			free(tmp);
		}
		i++;
	}
	return (NULL);
}

//Demande si c'est une commande, si oui, mets la commande en entier dans
//cmd_path, si non, erreur
void	search_path(t_data *data, int val)
{
	data->path = NULL;
	put_path_data(data);
	data->cmd[val].cmd_path = malloc(sizeof(char *) \
			* (2 + data->cmd[val].nbr_args));
	fill_cmd_path(data, val);
	data->cmd[val].cmd_path[0] = extract_exec(data, val);
	if (!data->cmd[val].cmd_path[0])
		return ;
	fill_arg_path(data, val);
	data->cmd[val].int_path = 1;
}
