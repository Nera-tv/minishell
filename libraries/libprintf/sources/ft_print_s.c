/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:15:18 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/20 12:25:13 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_s(int fd, char *s)
{
	if (!s)
	{
		ft_putstr_fd_pf("(null)", fd);
		return (4);
	}
	ft_putstr_fd_pf(s, fd);
	return (ft_strlen_pf(s) - 2);
}
