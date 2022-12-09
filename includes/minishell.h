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

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <signal.h>
# include <termios.h>
# include "error_msg.h"
# include "struct.h"
# include "../libraries/libft/libft.h"
# include "../libraries/libprintf/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>

# include <sys/types.h>
# include <sys/errno.h>
# include <sys/wait.h>

void	ft_exit(char *msg, t_data *data, int err_nbr);
void	read_line(const char *prompt, t_data *data);

// utils
size_t	ft_strlen_m(const char *tab);
size_t	len_until_char(char *str, int c);			// -> realloc_till_char.c
char	*realloc_till_char(char *str, int c, int f, t_data *data);// -> rea....c
char	*skip_this_char(char *str, int c);			// -> realloc_till_char.c
int		if_end_var_env(char c);

// parsing
void	get_cmd_arg(t_data *data);
void	free_data_cmd(t_data *data);
void	get_pwd(t_data *data);
void	get_redir(t_data *data, int val);
char	*cp_redir(char *str, int i, t_data *data);
int		get_redir_bis(t_data *data, int val, int i);
int		if_only_space(t_data *data);
int		ret_error_pipe_parse(t_data *data, char *msg);
int		check_line_pipe_go_back(t_data *data, int i);
int		check_line_redir(t_data *data);

// exec
void	wait_all_pids(t_data *data);							// -> wait.c
int		ft_execve(t_data *data, int cmd);						// -> exec.c
int		save_output(t_data *data, int cmd_to_exec);				// -> exec.c
int		ft_exec(t_data *data, int cmd_to_exec);					// -> exec.c

//		pipe
void	sep_cmd_pipe(t_data *data);
void	get_nbr_cmd(t_data *data);
int		check_line_pipe(t_data *data);
int		creating_pipes(t_data *data, int val);					// -> pipes.c
int		managing_pipes(t_data *data, int val);					// -> pipes.c

//		redirections
void	if_append(char *file_output, t_data *data, int val);// -> out_redir.c
void	if_trunc(char *file_output, t_data *data, int val);	// -> out_redir.c
void	if_heredoc(char *file_input, t_data *data, int val);	// -> in_redir.c
void	if_file_open(char *file_input, t_data *data, int val);	// -> in_redir.c
int		get_me_file_output(t_data *data, int val);			// -> out_redir.c
int		get_me_file_redirect(t_data *data, int val);		// -> out_redir.c
int		storing_file_output(char **file_outp, t_data *d, int val);// -> out_redi
int		opening_file_output(t_data *data, int val);		// -> opening_files.c
int		storing_file_input(char **file_input, t_data *data, int val);// -> in_re
int		fillin_my_here_doc(char *word, t_data *data);			// -> in_redir.c

//		path
void	search_path(t_data *data, int val);							// -> path.c
char	*add_slash_to_path(char *path);								// -> path.c
char	*access_check(char *cmd, char **path, t_data *data);		// -> path.c
int		put_path_data(t_data *data);								// -> path.c

//		signal
void	init_sig_callbacks(int flag);

//		cmd
void	get_cmd_name(t_data *data, int val);
void	check_cmd(t_data *data, int val);
void	check_cmd_slash(t_data *data, int val);
char	*ft_str_tolower(char *str);
char	*get_var_env_in_cmd(char *str, t_data *data);
char	*db_quote_in_cmd_bis(t_data *data, char *line, char *var_env);
char	*shift_in_tab(char *tab, int i);
char	*del_var_env_in_line(char *line);
char	*var_dollard_dollard(char *line);
int		get_cmd_len(t_data *data, int val);
int		sp_quote_in_cmd(char *line, int len);

//		args
void	get_args(t_data *data, int val);
void	get_args_len(t_data *data, int val);
void	ft_free_tab_arg(char **tab, int j);
void	free_args(char **args, int nbr_args);
char	*get_var_env_in_arg(char *str, t_data *data);
char	**set_var_args(t_data *data, int val);
char	*db_quote_in_arg_bis(t_data *data, char *line, char *var_env);
int		sp_quote_in_arg(char *line, int len);
int		db_quote_in_arg(t_data *data, int val, int len, int arg_count);
int		args_count_bis(char const *s, char c, int i);

//		var_env
size_t	ft_strlen_c(const char *s, char c);
void	ft_lst_env_fill(t_data *data);
void	new_env(t_data *data, char *name, char *content);
void	update_val_env(t_data *data, char *name, char *new_content);
void	del_env(t_data *data, char *name);
void	args_var_env(t_data *data, int val);
char	*ft_replace_word(const char *s, char *old_w, char *new_w, t_data *data);
int		get_len_for_lst_env(t_data *data);
int		if_var_env(char *str, char c);
int		ft_cmp_var_env(const char *s1, const char *s2);

//		builtins
void	ft_echo(t_data *data, int val);
void	ft_env(t_data *data);
void	ft_pwd(t_data *data);
void	check_arg(t_data *data, int val);
void	exec_builtins(t_data *data, int val, int blt);
void	exit_if_blt_exit(t_data *data, int val);
int		nb_args(char **args);
int		is_builtins(t_data *data, int val);
int		if_blt_only_arg_bis(t_data *data, int indic);
int		if_blt_only_arg(t_data *data);

//		cd
void	ft_cd(t_data *data, int val);
void	change_dir(t_data *data, char *path);
int		check_if_dash(t_data *data, int val);
int		check_if_tilde(t_data *data, int val);

//		export
void	ft_export(t_data *data, int val);
void	ft_swap(char **a, char **b);
void	ft_sort_and_print_env(t_data *data);
int		ft_strcmp_export(char *s1, char *s2);
int		ft_matricelen(char **matrice);

//		unset
void	ft_unset(t_data *data, int val);

//		printdata
void	print_data(t_data *data, int cmd);
#endif