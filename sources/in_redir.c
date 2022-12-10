/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:46:18 by tweidema          #+#    #+#             */
/*   Updated: 2022/12/10 14:35:25 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	if_file_open(char *file_input, t_data *data, int val)
{
	char	*till_next;
	int		fd;

	till_next = skip_this_char(&file_input[1], ' ');
	till_next = realloc_till_char(till_next, ' ', 0, data);
	fd = open(till_next, O_RDONLY);
	if (close(fd) < 0)
	{
		free (till_next);
		return ;
	}
	data->cmd[val].file_input = till_next;
	data->cmd[val].input_method = 1;
}

void	if_heredoc(char *file_input, t_data *data, int val)
{
	char	*till_next;

	till_next = skip_this_char(&file_input[2], ' ');
	till_next = realloc_till_char(till_next, ' ', 0, data);
	fillin_my_here_doc(till_next, data);
	data->cmd[val].file_input = ".minishell_heredoc";
	data->cmd[val].input_method = 2;
	free(till_next);
}

int	fillin_my_here_doc(char *word, t_data *data)
{
	size_t	word_len;
	char	*gnl;
	int		fd;

	word_len = ft_strlen(word);
	if (word_len == 0)
		ft_exit(ERRHDOC, data, 2);
	fd = open(".minishell_heredoc", O_CREAT | O_TRUNC | O_WRONLY,
			S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		ft_exit(ERRFD, data, 1);
	gnl = readline("here_doc $> ");
	while (gnl && (ft_strncmp(gnl, word, word_len)
			|| ft_strlen(gnl) != word_len))
	{
		write(fd, gnl, ft_strlen(gnl));
		ft_putchar_fd('\n', fd);
		free(gnl);
		gnl = readline("here_doc $> ");
	}
	free(gnl);
	if (close(fd) < 0)
		ft_exit(ERRFD, data, 1);
	return (0);
}

int	storing_file_input(char	**file_input, t_data *data, int val)
{
	int	i;

	i = 0;
	while (i < data->cmd[val].nb_redir)
	{
		if (file_input[i][0] == '<' && file_input[i][1] == '<')
			if_heredoc(file_input[i], data, val);
		else if (file_input[i][0] == '<')
			if_file_open(file_input[i], data, val);
		i++;
	}
	return (0);
}
