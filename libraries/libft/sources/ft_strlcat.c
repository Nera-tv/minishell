/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:07:20 by dvilard           #+#    #+#             */
/*   Updated: 2021/11/04 17:32:08 by dvilard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dstlen;
	int			i;

	s = src;
	dstlen = ft_strlen(dst);
	d = dst + dstlen;
	i = 0;
	if (size == 0 || size < dstlen)
		return (size + ft_strlen(s));
	while (s[i] != '\0' && dstlen + i < size - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (dstlen + ft_strlen(src));
}
