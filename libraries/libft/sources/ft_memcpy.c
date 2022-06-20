/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:17:26 by dvilard           #+#    #+#             */
/*   Updated: 2021/11/06 11:56:22 by dvilard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	const char		*source;

	if (!dest && !src)
		return (0);
	dst = dest;
	source = src;
	while (n-- > 0)
		*dst++ = *source++;
	return (dest);
}
