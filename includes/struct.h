/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:00:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/06/22 17:17:51 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data				t_data;
typedef struct s_pcmd				t_pcmd;
typedef struct s_exec				t_exec;
typedef struct s_value_while		t_value_while;

struct s_value_while
{
	int				i;
	int				j;
};


struct s_exec
{
	char			*file_input;
	char			*file_output;
	char			**envp;
	int				nb_cmd;
	int				pipein[2];
	int				pipeout[2];
	int				*fork_proc_id;	
};

struct s_pcmd
{
	char			*cmd;
	char			**args;
	int				ind_arg;
	int				nbr_args;
};

struct s_data
{
	t_pcmd			p_cmd;
	t_exec			exec;
	t_value_while	val_w;
	char			***cmd;
	char			**path;
	int				start;
	char			*cmdl;
	int				error;
	int				nb_env;
};

#endif
