/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:00:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/11/08 11:08:09 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int							g_status;

typedef struct s_data		t_data;
typedef struct s_cmd		t_cmd;
typedef struct s_arg		t_arg;
typedef struct s_list_env	t_list_env;

struct s_list_env
{
	char	*name;
	char	*content;
};

struct s_cmd
{
	char	*_cmd;
	char	*cmd;
	char	*cmd_wo_file;
	char	opt;
	char	*_args;
	char	*argl;
	char	**args;
	char	**cmd_path;
	char	*file_output;
	char	*file_input;
	char	**redirections;
	char	**redirection;
	int		nb_redir;
	int		if_redir;
	int		input_method;
	int		output_method;
	int		nbr_args;
	int		*args_len;
	int		pos_start_before_cmd_name;
	int		s_quotes_indic;
	int		d_quotes_indic;
	int		int_path;
};

struct s_data
{
	t_cmd			*cmd;
	int				nbr_cmds;
	int				start;
	char			*line;
	char			*pwd;
	char			**envp;
	char			**path;
	t_list_env		*env;
	int				nb_env;
	char			**argv;
	int				indic_first_cd;
	int				cnt_replace;
	int				*forkid;
	int				status;
	int				err_nbr;
	int				pipein[2];
	int				pipeout[2];
	struct termios	original;
	struct termios	silent;
};

#endif
