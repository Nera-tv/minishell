/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:09:09 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/07 13:30:13 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp_export(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (((unsigned char) *s1 - (unsigned char) *s2) > 0)
	{
		return (1);
	}
	else if (((unsigned char) *s1 - (unsigned char) *s2) < 0)
	{
		return (-1);
	}
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_putstr_fd_export(char *s, int fd)
{
	int		i;
	int		j;
	char	c;

	if (!s || !fd)
		return ;
	i = 0;
	j = 0;
	c = '\"';
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		if (j == 0 && s[i] == '=')
		{
			ft_putchar_fd('\"', fd);
			j = 1;
		}
		i++;
	}
	ft_putchar_fd('\"', fd);
}

char	**cp_matrice(char **matrice, int nb_val, t_data *data)
{
	char	**matrice_cp;
	int		i;

	matrice_cp = malloc(sizeof(char *) * nb_val);
	if (!matrice_cp)
		ft_exit(ERRMEMALLOC, data);
	i = 0;
	while (matrice[i])
	{
		matrice_cp[i] = matrice[i];
		i++;
	}
	return (matrice_cp);
}

void	ft_sort_and_print_env(int nb_val, char **env, t_data *data)
{
	int		i;
	int		j;
	char	**envcp;

	i = 0;
	envcp = cp_matrice(env, nb_val, data);
	while (i++ < nb_val)
	{
		j = i + 1;
		while (j < nb_val)
		{
			if (ft_strcmp_export(envcp[i], envcp[j]) == 1)
				ft_swap(&envcp[i], &envcp[j]);
			j++;
		}
	}
	i = 0;
	while (++i < nb_val)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd_export(envcp[i], 1);
		write(1, "\n", 1);
	}
	free(envcp);
}
