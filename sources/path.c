/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweidema <tweidema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:48:30 by tweidema          #+#    #+#             */
/*   Updated: 2022/11/28 14:50:04 by tweidema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//Regarde si la commande est possible, si non, essaie de voir si la commande
//peut correspondre avec un des PATH et être exécuté, si non, revoie NULL
char	*access_check(char *cmd, char **path, t_data *data)
{
	int		i;
	char	*ret;

	i = 0;
	if (!cmd || !path)
		return (NULL);
	if (!access(cmd, X_OK))
		return (cmd);
	while (path[i])
	{
		ret = ft_strjoin(path[i], cmd);
		if (!ret)
			ft_exit(ERRMEMALLOC, data);
		if (!access(ret, X_OK))
			return (ret);
		free(ret);
		i++;
	}
	return (NULL);
}

//Va chercher dans la variable d'environnement l'emplacement de PATH
char	*search_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

//Met un "/" à la fin de chaque PATH pour pouvoir directement mettre la commande
//derrière
char	*add_slash_to_path(char *path)
{
	char	*ret;

	ret = ft_strjoin(path, "/");
	if (!ret)
		return (NULL);
	free(path);
	return (ret);
}

//Va chercher le PATH puis les sépare en plusieurs case pour que ce soit plus
//facile à manipuler
int	put_path_data(t_data *data)
{
	char	*path;
	int		i;

	i = 0;
	path = search_path_env(data->envp);
	if (!path)
		return (-1);
	data->path = ft_split(path, ':');
	if (!data->path)
		return (-1);
	while (data->path[i])
	{
		data->path[i] = add_slash_to_path(data->path[i]);
		if (!data->path[i])
			return (-1);
		i++;
	}
	return (0);
}

void	fill_cmd_path(t_data *data, int val)
{
	int	i;

	i = 0;
	while (i < data->cmd[val].nbr_args + 2)
	{
		data->cmd[val].cmd_path[i] = NULL;
		i++;
	}
}

void	fill_arg_path(t_data *data, int val)
{
	int	i;

	i = 1;
	while (i < data->cmd[val].nbr_args + 1)
	{
		printf("%s\n", data->cmd[val].args[i - 1]);
		data->cmd[val].cmd_path[i] = data->cmd[val].args[i - 1];
		i++;
	}
}

//Demande si c'est une commande, si oui, mets la commande en entier dans
//cmd_path, si non, erreur
int	search_path(t_data *data, int val)
{
	char	*pathok;

	data->cmd[val].cmd_path = malloc(sizeof(char *) * (2 + data->cmd[val].nbr_args));
	fill_cmd_path(data, val);
	pathok = access_check(ft_strdup(data->cmd[val].cmd), data->path, data);
	if (!pathok)
		return (-1);
	data->cmd[val].cmd_path[0] = pathok;
	fill_arg_path(data, val);
	return (0);
}
