/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:45:22 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/20 12:25:59 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_analyse_percent(int fd, const char*str, size_t i, va_list a)
{
	if (str[i] == 'c')
		return (ft_print_c(fd, va_arg(a, int )));
	else if (str[i] == 's')
		return (ft_print_s(fd, va_arg(a, char *)));
	else if (str[i] == 'p')
		return (ft_print_p(fd, va_arg(a, void *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_print_d(fd, va_arg(a, int)));
	else if (str[i] == 'u')
		return (ft_print_u(fd, va_arg(a, unsigned int)));
	else if (str[i] == 'x')
		return (ft_print_x(fd, va_arg(a, unsigned int )));
	else if (str[i] == 'X')
		return (ft_print_upx(fd, va_arg(a, unsigned int)));
	else if (str[i] == '%')
		return (ft_print_percent(fd));
	return (0);
}

int	char_verif(char c)
{
	char	*base;
	int		i;

	i = 0;
	base = "cspdiuxX%";
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	a;
	size_t	i;
	size_t	val;

	va_start(a, str);
	if (!str)
		return (-1);
	i = 0;
	val = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && char_verif(str[i + 1]) == 1)
		{
			val += ft_analyse_percent(fd, str, i + 1, a);
			i++;
		}
		else if (str[i] != '%')
			ft_putchar_fd_pf(str[i], fd);
		i++;
	}
	return (i + val);
}
