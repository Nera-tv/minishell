/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_args_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:27:59 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/01 10:16:12 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_args_len(t_data *data, int val)
{
	int	i;

	i = 0;
	data->cmd[val].args_len = malloc(sizeof(int)
			* nb_args(data->cmd[val].args));
	if (!data->cmd[val].args_len)
		ft_exit(ERRMEMALLOC, data, 2);
	while (i < data->cmd[val].nbr_args)
	{
		data->cmd[val].args_len[i] = ft_strlen(data->cmd[val].args[i]);
		i++;
	}
}

size_t	ft_strlen_m(const char *tab)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (tab[i] == ' ')
		i++;
	while (tab[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}
