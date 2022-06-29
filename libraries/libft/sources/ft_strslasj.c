/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslasj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:51:55 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/22 12:49:19 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strslasj(char const *str1, char const *str2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ret;

	i = -1;
	j = -1;
	if (!str1 || !str2)
		return (0);
	len = (ft_strlen(str1) + ft_strlen(str2));
	ret = malloc(sizeof(char) * (len + 2));
	if (!ret)
		return (0);
	while (str1[++i] != '\0')
		ret[i] = str1[i];
	ret[i] = '/';
	i++;
	while (str2[++j] != '\0')
		ret[i + j] = str2[j];
	ret[i + j] = '\0';
	return (ret);
}
