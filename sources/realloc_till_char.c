/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_till_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:47:02 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/07 11:07:47 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	len_until_char(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != (char)c)
		i++;
	return (i);
}

char	*realloc_till_char(char *str, int c, int need_free, t_data *data)
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = len_until_char(str, c);
	if (len == 0)
		return (NULL);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		ft_exit(ERRMEMALLOC, data, 1);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	if (need_free == 1)
		free(str);
	return (ret);
}

char	*skip_this_char(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] == (char)c)
		i++;
	return (&str[i]);
}
