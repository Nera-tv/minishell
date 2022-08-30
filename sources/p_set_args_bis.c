/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_set_args_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:15:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/30 20:53:06 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	args_count_bis(char const *s, char c, int i)
{
	i++;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (i - 1);
	else
		return (i);
}

void	ft_free_tab_arg(char **tab, int j)
{
	int	i;

	i = 0;
	while (i != j)
		free(tab[i++]);
	free(tab);
}
