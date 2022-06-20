/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:43:17 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/20 12:25:41 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_upx(int fd, unsigned int d)
{
	int	i;

	ft_putnbr_base_hexa_fd(d, 2, fd);
	i = 0;
	if (d == 0)
		return (-1);
	while (d)
	{
		d = d / 16;
		i++;
	}
	return (i - 2);
}

int	ft_print_x(int fd, unsigned int d)
{
	int	i;

	ft_putnbr_base_hexa_fd(d, 1, fd);
	i = 0;
	if (d == 0)
		return (-1);
	while (d)
	{
		d = d / 16;
		i++;
	}
	return (i - 2);
}
