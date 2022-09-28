/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:14:35 by dvilard           #+#    #+#             */
/*   Updated: 2022/09/20 22:49:42 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*del_var_env_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '$')
		i++;
	line = shift_in_tab(line, i);
	while (if_end_var_env(line[i]) != 1)
		line = shift_in_tab(line, i);
	return (line);
}

char	*shift_in_tab(char *tab, int i)
{
	while (tab[i] != '\0')
	{
		tab[i] = tab[i + 1];
		i++;
	}
	return (tab);
}
