/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:00:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/08/27 13:30:16 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data		t_data;
typedef struct s_cmd		t_cmd;

struct s_cmd
{
	char	*_cmd;
	char	*cmd;
	char	opt;
	char	*_args;
	char	*argl;
	char	**args;
	int		nbr_args;
	int		*args_len;
	int		pos_start_before_cmd_name;
	int		s_quotes_indic;
	int		d_quotes_indic;
};

struct s_data
{
	t_cmd			*cmd;
	int				nbr_cmds;
	int				start;
	char			*line;
	char			*pwd;
	char			**envp;
	char			**argv;
	int				indic_first_cd;
	int				error;
};

#endif
