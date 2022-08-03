/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neress <neress@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:00:41 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/03 07:49:22 by neress           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "error_msg.h"
# include "struct.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>
# include "../libraries/libft/libft.h"
# include "../libraries/libprintf/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>

#include <sys/types.h>
#include <sys/wait.h>

void	ft_exit(char *msg, t_data *data);
void	read_line(const char *prompt, t_data *data);

// parsing
void	get_cmd_arg(t_data *data);
void	get_nbr_cmd(t_data *data);
int		if_only_space(t_data *data);
void    get_args(t_data *data, int val);
void	free_data_cmd(t_data *data);

// builtins
void    ft_echo(t_data *data, int val);
void	ft_env(t_data *data);
void	ft_pwd(t_data *data);
int		is_builtins(t_data *data, int val);
void    exec_builtins(t_data *data, int val, int blt);

#endif