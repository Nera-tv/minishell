/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:48:30 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/01 15:04:23 by dvilard          ###   ########.fr       */
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
		printf("%s\n", data->cmd[val].args[i - 1]);
		data->cmd[val].cmd_path[i] = data->cmd[val].args[i - 1];
		i++;
	}
}

//Demande si c'est une commande, si oui, mets la commande en entier dans
//cmd_path, si non, erreur
void	search_path(t_data *data, int val)
{
	char	*pathok;
	char	*tmp;

	data->cmd[val].cmd_path = malloc(sizeof(char *) \
			* (2 + data->cmd[val].nbr_args));
	fill_cmd_path(data, val);
	tmp = ft_strdup(data->cmd[val].cmd);
	pathok = access_check(tmp, data->path, data);
	if (!pathok)
		pathok = ft_strdup(data->cmd[val].cmd);
	data->cmd[val].cmd_path[0] = pathok;
	fill_arg_path(data, val);
	data->cmd[val].int_path = 1;
	if (&tmp < &pathok)
		free(tmp);
}
