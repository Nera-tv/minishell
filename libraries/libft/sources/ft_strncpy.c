/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:48:22 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/30 18:32:22 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	size;

	size = ft_strnlen(s2, n);
	if (size != n)
		ft_memset(s1 + size, '\0', n - size);
	ft_memcpy(s1, s2, size);
	return (s1);
}
