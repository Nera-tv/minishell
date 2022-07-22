/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:55:31 by dvilard           #+#    #+#             */
/*   Updated: 2022/07/22 13:45:40 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    print_echo(int option, char *msg)
{
    if (option == 0) // sans -n
    {
        ft_putstr_fd(msg, 1);
        ft_putchar_fd('\n', 1);
    }
    if (option == 1) // avec -n
        ft_putstr_fd(msg, 1);
}

void ft_echo(t_data *data, int val)
{
    if (data->cmd[val].opt == 'n')
        print_echo(1, data->cmd[val]._args);
    else
        print_echo(0, data->cmd[val]._args);
}