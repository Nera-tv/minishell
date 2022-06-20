/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:01:20 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/20 12:24:55 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_p(int fd, void *ptr)
{
	unsigned long	adr;
	int				i;

	ft_putadress_fd(ptr, fd);
	adr = (unsigned long)ptr;
	i = 0;
	if (adr == 0)
		return (1);
	while (adr > 0)
	{
		adr /= 16;
		i++;
	}
	return (i);
}
