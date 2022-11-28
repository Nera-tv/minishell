/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_cmd_arg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:43:40 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/29 00:06:15 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	if_only_space(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] != '\0')
	{
		if (data->line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_line_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] == ' ')
		i++;
	if (data->line[i] == '|' && data->line[i + 1] != '|')
	{
		//mettre la sortie d'erreur sur 2
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 1);
		return (1);
	}
	else if (data->line[i] == '|' && data->line[i + 1] == '|')
	{
		//mettre la sortie d'erreur sur 2
		ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 1);
		return (1);
	}
	else if (data->line[i] == '\0')
		return (1);
	return (0);
}

void	get_nbr_cmd(t_data *data)
{
	int	i;

	data->nbr_cmds++;
	i = 0;
	while (data->line[i++] != '\0')
	{
		if (data->line[i] == '|')
			data->nbr_cmds++;
	}
}
