/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:28:22 by dvilard           #+#    #+#             */
/*   Updated: 2021/11/16 15:18:05 by dvilard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' )
		return (1);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_check_long(long n, int s, const char *str, int i)
{
	if ((n * 10 + (str[i] - '0')) / 10 != n && s == -1)
		return (0);
	else if ((n * 10 + (str[i] - '0')) / 10 != n)
		return (-1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	val;
	int		sign;

	i = 0;
	val = 0;
	sign = 1;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]) == 1)
	{
		if (ft_check_long(val, sign, nptr, i) == 0)
			return (0);
		else if (ft_check_long(val, sign, nptr, i) == -1)
			return (-1);
		val = (val * 10) + (nptr[i++] - 48);
	}
	return ((int )val * sign);
}
