/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:34:12 by dvilard           #+#    #+#             */
/*   Updated: 2022/12/01 15:02:26 by dvilard          ###   ########.fr       */
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
			ft_exit(ERRMEMALLOC, data, 2);
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
