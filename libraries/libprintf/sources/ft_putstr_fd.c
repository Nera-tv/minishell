/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:41:31 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/20 12:05:16 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr_fd_pf(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen_pf(s));
}
