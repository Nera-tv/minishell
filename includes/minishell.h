/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:00:41 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/08 11:53:20 by dvilard          ###   ########.fr       */
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
int		if_end_var_env(char c);

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
int		get_cmd_len(t_data *data, int val);
char	*ft_str_tolower(char *str);
int		sp_quote_in_cmd(char *line, int len);
char	*get_var_env_in_cmd(char *str);
char	*db_quote_in_cmd_bis(t_data *data, char *line, char *var_env);
char	*shift_in_tab(char *tab, int i);
char	*del_var_env_in_line(char *line);
char	*var_dollard_dollard(char *line);

//		args
void	get_args(t_data *data, int val);
void	get_args_len(t_data *data, int val);
char	**set_var_args(t_data *data, int val);
int		args_count_bis(char const *s, char c, int i);
void	ft_free_tab_arg(char **tab, int j);
void	free_args(char **args, int nbr_args);
char	*db_quote_in_arg_bis(t_data *data, char *line, char *var_env);
int		sp_quote_in_arg(char *line, int len);
int		db_quote_in_arg(t_data *data, int val, int len, int arg_count);
char	*get_var_env_in_arg(char *str);

//		var_env
void	ft_lst_env_fill(t_data *data);
int		get_len_for_lst_env(t_data *data);
void	new_env(t_data *data, char *name, char *content);
void	update_val_env(t_data *data, char *name, char *new_content);
void	args_var_env(t_data *data, int val);
char	*ft_replace_word(const char *s, char *old_w, char *new_w);
size_t	ft_strlen_c(const char *s, char c);
int		if_var_env(char *str, char c);
int		ft_cmp_var_env(const char *s1, const char *s2);

// builtins
void	ft_echo(t_data *data, int val);
int		nb_args(char **args);
void	ft_env(t_data *data);
void	ft_pwd(t_data *data);
void	check_arg(t_data *data, int val);
int		is_builtins(t_data *data, int val);
void	exec_builtins(t_data *data, int val, int blt);

//cd
void	ft_cd(t_data *data, int val);
void	change_dir(t_data *data, char *path);
int		check_if_dash(t_data *data, int val);
int		check_if_tilde(t_data *data, int val);

// export
void	ft_export(t_data *data, int val);
int		ft_strcmp_export(char *s1, char *s2);
void	ft_swap(char **a, char **b);
void	ft_sort_and_print_env(int nb_val, char **env, t_data *data);
int		ft_matricelen(char **matrice);

#endif