/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_var_env_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:58:47 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:15:08 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	if_var_env(char *str, char c)
{
	int	i;
	int	dollar_count;

	i = 0;
	dollar_count = 0;
	while (str[i] != c)
		i++;
	i++;
	while (str[i] != c && str[i] != '\0')
	{
		if (str[i] == '$')
			dollar_count++;
		i++;
	}
	return (dollar_count);
}

int	if_end_var_env(char c)
{
	if (ft_isalnum(c) == 0)
		return (1);
	return (0);
}

int	ft_cmp_var_env(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s2[j] != '=')
	{
		if (s1[i] == '\0' && s2[j] != '\0')
			return (1);
		if (s1[i] != s2[j])
			return (1);
		i++;
		j++;
	}
	if (s1[i] != '\0' && s2[j] == '=')
		return (1);
	return (0);
}
