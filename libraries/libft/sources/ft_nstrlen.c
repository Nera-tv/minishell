/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:23:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/26 01:09:38 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_nstrlen(const char *tab, size_t i)
{
	size_t	j;

	j = i;
	while (tab[i] != '\0')
		i++;
	return (i - j);
}
