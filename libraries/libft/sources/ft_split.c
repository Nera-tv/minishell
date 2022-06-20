/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:43:39 by dvilard           #+#    #+#             */
/*   Updated: 2021/11/16 15:23:19 by dvilard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_get_word_len(const char *tab, char c)
{
	size_t	i;

	i = 0;
	while (tab[i] != '\0' && tab[i] != c)
		i++;
	return (i);
}

int	ft_word_count(char const *s, char c)
{
	int	wc;
	int	i;
	int	in_word;

	in_word = 0;
	wc = 0;
	i = 0;
	while (s[i])
	{
		if (in_word && s[i] == c)
			in_word = 0;
		else if (!in_word && s[i] != c)
		{
			in_word = 1;
			wc++;
		}
		i++;
	}
	return (wc);
}

void	ft_free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i++ != j)
		free(tab[j]);
	free(tab);
}

char	**ft_cpy_str_to_tab(char **tab, const char *s, char c, int it[2])
{
	int	j;
	int	word_len;

	j = 0;
	while (j < it[1])
	{
		word_len = ft_get_word_len((char *)s + it[0], c);
		tab[j] = ft_substr((char *)s + it[0], 0, word_len);
		if (!tab[j])
		{
			ft_free_tab(tab, j);
			return (0);
		}
		it[0] += word_len;
		while (s[it[0]] != '\0' && s[it[0]] == c)
			it[0] += 1;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		it[2];
	int		wc;
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	wc = ft_word_count(&s[i], c);
	tab = malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (0);
	it[0] = i;
	it[1] = wc;
	tab = ft_cpy_str_to_tab(tab, s, c, it);
	return (tab);
}
