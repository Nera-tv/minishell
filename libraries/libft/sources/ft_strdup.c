/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:01:11 by dvilard           #+#    #+#             */
/*   Updated: 2021/11/08 12:05:52 by dvilard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = malloc(sizeof (char) * ft_strlen(s) + 1);
	if (!dup)
		return (0);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}
