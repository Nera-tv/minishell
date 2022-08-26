/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:27:59 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 12:31:54 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen_m(const char *tab)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (tab[i] == ' ')
		i++;
	while (tab[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}
