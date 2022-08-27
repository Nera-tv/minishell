/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:00:41 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/27 16:05:58 by dvilard          ###   ########.fr       */
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

# include <sys/types.h>
# include <sys/wait.h>

void	ft_exit(char *msg, t_data *data);
void	read_line(const char *prompt, t_data *data);

// utils
size_t	ft_strlen_m(const char *tab);

// parsing
void	get_cmd_arg(t_data *data);
int		if_only_space(t_data *data);
void	free_data_cmd(t_data *data);
void	get_pwd(t_data *data);
//		pipe
void	sep_cmd_pipe(t_data *data);
int		check_line_pipe(t_data *data);
void	get_nbr_cmd(t_data *data);
//		cmd
void	get_cmd_name(t_data *data, int val);
//		args
void	get_args(t_data *data, int val);
void	get_args_len(t_data *data, int val);
void	free_args(char **args, int nbr_args);

// builtins
void	ft_echo(t_data *data, int val);
int		nb_args(char **args);
void	ft_env(t_data *data);
void	ft_pwd(t_data *data);
void	ft_cd(t_data *data, int val);
void	change_dir(t_data *data, char *path);
void	check_arg(t_data *data, int val);
int		is_builtins(t_data *data, int val);
void	exec_builtins(t_data *data, int val, int blt);

#endif