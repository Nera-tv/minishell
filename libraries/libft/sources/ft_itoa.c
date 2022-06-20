/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:22:48 by dvilard           #+#    #+#             */
/*   Updated: 2021/11/10 18:07:35 by dvilard          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_get_len_int(unsigned long n)
{
	int	i;

	if (!n)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_int_to_a(char *str, unsigned long vals[3])
{
	int	i;

	i = 0;
	if (vals[0])
		str[0] = '-';
	str[(vals[2] + vals[0]) - 1] = '0';
	while (vals[1] > 0)
	{
		str[(vals[2] + vals[0]) - 1 - i] = (vals[1] % 10) + '0';
		vals[1] /= 10;
		i++;
	}
	str[vals[2] + vals[0]] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned long	vals[3];

	vals[0] = 0;
	vals[1] = n;
	if (n < 0)
	{
		vals[1] = (unsigned int)-n;
		vals[0] = 1;
	}
	vals[2] = ft_get_len_int(vals[1]);
	str = malloc(sizeof(char ) * (vals[2] + vals[0] + 1));
	if (!str)
		return (0);
	return (ft_int_to_a(str, vals));
}
