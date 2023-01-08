/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:55:17 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/07 13:55:43 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ctrlslash_handler_bis(int sig, siginfo_t *info, void *ctx)
{
	(void)sig;
	(void)info;
	(void)ctx;
}

void	ctrlslash_handler(int a, siginfo_t *t, void *c)
{
	if (g_status == 1)
	{
		write(2, "Quit: 3\n", 8);
	}
	else if (g_status == 0)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	(void)a;
	(void)t;
	(void)c;
}

void	ctrlc_handler_bis(int sig, siginfo_t *info, void *ctx)
{
	(void)sig;
	(void)info;
	(void)ctx;
}

void	ctrlc_handler(int sig, siginfo_t *info, void *ctx)
{
	if (g_status == 3)
	{
		g_status = 128 + dup(0);
		close(0);
	}
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (g_status == 0)
		rl_redisplay();
	(void)sig;
	(void)info;
	(void)ctx;
}

void	init_sig_callbacks(int flag)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(struct sigaction));
	act.sa_sigaction = ctrlc_handler;
	if (flag)
		act.sa_sigaction = ctrlc_handler_bis;
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGINT, &act, NULL);
	act.sa_sigaction = ctrlslash_handler;
	if (flag)
		act.sa_sigaction = ctrlslash_handler_bis;
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGQUIT, &act, NULL);
	(void)flag;
}
