/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_var_env_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:58:47 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/31 01:08:04 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen_c(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

int	if_var_env(char *str, char c)
{
	int	i;
	int	dollar_count;

	i = 0;
	dollar_count = 0;
	while (str[i] != c)
		i++;
	i++;
	while (str[i] != c && str[i] != '\0')
	{
		if (str[i] == '$')
			dollar_count++;
		i++;
	}
	return (dollar_count);
}

int	if_end_var_env(char c)
{
	if (c == '\0' || c == '\\' || c == '\'' || c == '\"')
		return (1);
	return (0);
}

char	*get_var_env_in_arg(char *str)
{
	char	*env;
	int		i;
	int		len;

	i = 0;
	env = NULL;
	while (str[i] != '$')
		i++;
	len = 0;
	while (if_end_var_env(str[i + len]) != 1)
		len++;
	env = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (if_end_var_env(str[i + len]) != 1)
	{
		env[len] = str[i + len];
		len++;
	}
	env[len] = '\0';
	return (env);
}

int	ft_cmp_var_env(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s2[j] != '=')
	{
		if (s1[i] == '\0' && s2[j] != '\0')
			return (1);
		if (s1[i] != s2[j])
			return (1);
		i++;
		j++;
	}
	if (s1[i] != '\0' && s2[j] == '=')
		return (1);
	return (0);
}
