/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:24:44 by dvilard           #+#    #+#             */
/*   Updated: 2021/11/13 13:34:51 by dvilard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;

	if (!dest && !src)
		return (0);
	dst = dest;
	source = src;
	if (dst < source)
		ft_memcpy(dst, source, n);
	else
	{
		dst = dst + (n - 1);
		source = source + (n - 1);
		while (n-- > 0)
			*dst-- = *source--;
	}
	return (dest);
}
