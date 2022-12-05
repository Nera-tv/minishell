/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_back_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:40:30 by dvilard           #+#    #+#             */
/*   Updated: 2022/10/27 16:05:26 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen_c_to_c(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] != '\0')
	{
		i++;
		while (s[i] != c)
		{
			if (s[i] == '\0')
				return (i);
			i++;
		}
	}
	return (i);
}

void	remove_quote_in_back_slash(t_data *data, int val, int arg_count)
{
	int	i;

	i = ft_strlen_c_to_c(data->cmd[val].args[arg_count], '\\');
}
