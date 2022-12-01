/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_set_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:37:38 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/01 10:33:40 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	get_arg_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != ' ' && s[i] != '\0')
	{
		if (s[i] == '\'')
			i = args_count_bis(s, '\'', i) + 1;
		else if (s[i] == '\"')
			i = args_count_bis(s, '\"', i) + 1;
		else
			i++;
	}
	return (i);
}

int	args_count(char const *s)
{
	int	ac;
	int	i;

	ac = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != ' ' && s[i] != '\0')
		{
			if (s[i] == '\'')
				i = args_count_bis(s, '\'', i) + 1;
			else if (s[i] == '\"')
				i = args_count_bis(s, '\"', i) + 1;
			else
				i++;
		}
		ac++;
		while (s[i] == ' ')
			i++;
	}
	return (ac);
}

char	**ft_cpy_arg_to_tab(char **tab, const char *s, int ac)
{
	int	j;
	int	i;
	int	arg_len;

	j = 0;
	i = 0;
	while (j < ac)
	{
		arg_len = get_arg_len((char *)s + i);
		tab[j] = ft_substr((char *)s + i, 0, arg_len);
		if (!tab[j])
		{
			ft_free_tab_arg(tab, j);
			return (0);
		}
		i += arg_len;
		while (s[i] == ' ' && s[i] != '\0')
			i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**set_var_args(t_data *data, int val)
{
	int		ac;
	char	**tab;

	ac = args_count(data->cmd[val]._args);
	tab = malloc(sizeof(char *) * (ac + 1));
	if (!tab)
		ft_exit (ERRMEMALLOC, data, 2);
	tab = ft_cpy_arg_to_tab(tab, data->cmd[val]._args, ac);
	return (tab);
}
