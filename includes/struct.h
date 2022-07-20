/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:00:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/07/20 20:55:26 by dvilard          ###   ########.fr       */
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
	char	*cmd;
	char	**args;
	int		nbr_args;
	int		s_quotes_indic;
	int		d_quotes_indic;
};


struct s_data
{
	t_cmd			*cmd;
	int				nbr_cmds;
	int				start;
	char			*cmdl;
	int				error;
};

#endif
