/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:07:37 by dvilard           #+#    #+#             */
/*   Updated: 2021/11/16 16:45:21 by dvilard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

static char	*ft_emptystr(char *str)
{
	str = malloc(sizeof (char) * 1);
	if (!str)
		return (0);
	str[0] = '\0';
	return (str);
}

size_t	ft_get_size(size_t len, unsigned int start, const char *s)
{
	if (len > ft_strlen(s) - start)
		return (ft_strlen(s) - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = 0;
	if (s == 0)
		return (0);
	if (start <= ft_strlen(s))
		str = ft_calloc(sizeof (char), ft_get_size(len, start, s) + 1);
	else
		return (ft_emptystr(str));
	if (!str)
		return (0);
	while (i < len && i < ft_strlen(&s[start]))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
