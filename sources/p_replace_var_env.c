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

char	*if_no_new_w(char *new_w, t_data *data)
{
	new_w = malloc(sizeof(char) * 1);
	if (!new_w)
		ft_exit(ERRMEMALLOC, data, 2);
	new_w[0] = '\0';
	return (new_w);
}

char	*replace_word_bis(const char *s, const char *old_w,
	char *new_w, char *result)
{
	int		new_w_len;
	int		old_w_len;
	int		i;
	int		cnt;

	new_w_len = ft_strlen(new_w);
	old_w_len = ft_strlen(old_w);
	i = 0;
	cnt = 0;
	while (*s)
	{
		if (ft_strstr(s, old_w) == s && cnt == 0)
		{
			ft_strcpy(&result[i], new_w);
			i += new_w_len;
			s += old_w_len;
			cnt++;
		}
		else
			result[i++] = *s++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_replace_word_while(const char *s, char *old_w,
	int old_w_len, t_data *data)
{
	int	i;

	data->cnt_replace = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strstr(&s[i], old_w) == &s[i] && data->cnt_replace == 0)
		{
			data->cnt_replace++;
			i += old_w_len - 1;
		}
		i++;
	}
	return (i);
}

char	*ft_replace_word(const char *s, char *old_w, char *new_w, t_data *data)
{
	char	*result;
	int		res;
	int		new_w_len;
	int		old_w_len;

	if (!new_w)
	{
		new_w = if_no_new_w(new_w, data);
		new_w_len = 1;
	}
	else
		new_w_len = ft_strlen(new_w);
	old_w_len = ft_strlen(old_w);
	res = ft_replace_word_while(s, old_w, old_w_len, data);
	result = malloc(sizeof(char) * (res + data->cnt_replace
				* (new_w_len - old_w_len) + 1));
	if (!result)
		ft_exit(ERRMEMALLOC, data, 2);
	result = replace_word_bis(s, old_w, new_w, result);
	return (result);
}
