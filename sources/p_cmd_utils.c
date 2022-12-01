/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cmd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:14:35 by dvilard           #+#    #+#             */
/*   Updated: 2022/10/27 11:22:07 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	sp_quote_in_cmd(char *line, int len)
{
	line = shift_in_tab(line, len);
	while (line[len] != '\0' && line[len] != '\'')
		len++;
	if (line[len] == '\'')
		line = shift_in_tab(line, len);
	if (len > 0)
		len--;
	return (len);
}

char	*ft_str_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

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
