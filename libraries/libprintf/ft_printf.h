/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:07:04 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/20 12:24:10 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(int fd, const char *str, ...);
int		ft_analyse_percent(int fd, const char*str, size_t i, va_list a);
int		ft_print_d(int fd, int d);
int		ft_print_p(int fd, void *ptr);
int		ft_print_percent(int fd);
int		ft_print_s(int fd, char *s);
int		ft_print_u(int fd, unsigned int d);
int		ft_print_x(int fd, unsigned int d);
int		ft_print_upx(int fd, unsigned int d);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
void	ft_putadress_fd(void *ptr, int fd);
void	ft_putchar_fd_pf(char c, int fd);
void	ft_putnbr_base_hexa_fd(unsigned int nbr, int mode, int fd);
void	ft_putnbr_fd_pf(int n, int fd);
void	ft_putstr_fd_pf(char *s, int fd);
size_t	ft_strlen_pf(const char *tab);
size_t	ft_print_c(int fd, char c);

#endif
