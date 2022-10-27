/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_replace_var_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:19:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/10/27 15:31:29 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_shiftstr(char *str, char c)
{
	int		i;
	int		y;
	char	*tmp;

	i = 0;
	y = 0;
	while (str[i] != c)
		i++;
	i++;
	while (str[i + y] != '\0')
		y++;
	tmp = malloc(sizeof(char) * (y + 1));
	y = 0;
	while (str[i + y] != '\0')
	{
		tmp[y] = str[i + y];
		y++;
	}
	tmp[y] = '\0';
	return (tmp);
}

char	*replace_word_bis(const char *s, const char *old_w,
	char *new_w, char *result)
{
	int		new_w_len;
	int		old_w_len;
	int		i;

	new_w_len = ft_strlen(new_w);
	old_w_len = ft_strlen(old_w);
	i = 0;
	while (*s)
	{
		if (ft_strstr(s, old_w) == s)
		{
			ft_strcpy(&result[i], new_w);
			i += new_w_len;
			s += old_w_len;
		}
		else
			result[i++] = *s++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_replace_word(const char *s, char *old_w, char *new_w)
{
	char	*result;
	int		i;
	int		cnt ;
	int		new_w_len;
	int		old_w_len;

	cnt = 0;
	if (new_w)
		new_w = ft_shiftstr(new_w, '=');
	new_w_len = ft_strlen(new_w);
	old_w_len = ft_strlen(old_w);
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strstr(&s[i], old_w) == &s[i])
		{
			cnt++;
			i += old_w_len - 1;
		}
		i++;
	}
	result = malloc(sizeof(char) * (i + cnt * (new_w_len - old_w_len) + 1));
	result = replace_word_bis(s, old_w, new_w, result);
	free(new_w);
	return (result);
}
