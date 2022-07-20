/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:55:31 by dvilard           #+#    #+#             */
/*   Updated: 2022/07/20 15:31:20 by dvilard          ###   ########.fr       */
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

int     if_only_echo(t_data *data)
{
    int i;
    
    i = 0;
    while (data->cmdl[i] == ' ')
        i++;
    while (data->cmdl[i] == 'e' || data->cmdl[i] == 'c' || data->cmdl[i] == 'h' || data->cmdl[i] == 'o')
        i++;
    if (data->cmdl[i] == '\0')
    {
        print_echo(0, "");
        return (1);
    }
    else
    {
        i++;
        if (data->cmdl[i] != '\0' && data->cmdl[i] == '-' && data->cmdl[i + 1] == 'n')
        {
            print_echo(1, "");
            i += 2;
        }
        if (data->cmdl[i] == '\0')
            return (1);
    }
    return (0);
}

void ft_echo(t_data *data)
{
    int option;
    int i;
    
    i = 0;
    if (if_only_echo(data) == 0)
    {
        while (data->cmdl[i] == ' ')
            i++;
        while (data->cmdl[i] != ' ')
            i++;
        while (data->cmdl[i] == ' ')
            i++;
        if (data->cmdl[i] == '-' && data->cmdl[i + 1] == 'n')
        {
            option = 1;
            printf("%d\n", option);
            i += 3;
        }
        while (data->cmdl[i] == ' ')
            i++;
        while (data->cmdl[i] != '\0')
            ft_putchar_fd(data->cmdl[i++], 1);
        ft_putchar_fd('\n', 1);
    }
}