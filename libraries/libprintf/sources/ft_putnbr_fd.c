/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:07:10 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/20 12:05:46 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_fd_pf(int n, int fd)
{
	char	i;

	if (n == -2147483648)
		ft_putstr_fd_pf("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd_pf('-', fd);
		}
		i = n % 10 + '0';
		if (n > 9)
			ft_putnbr_fd_pf(n / 10, fd);
		ft_putchar_fd_pf(i, fd);
	}
}
