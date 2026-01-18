/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:50:40 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/18 20:53:51 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_join_path(char *dir, char *cmd)
{
	char	*path_tmp;
	char	*path_complete;

	if (!dir || !cmd)
		return (NULL);
	path_tmp = ft_strjoin(dir, "/");
	if (!path_tmp)
		return(NULL);
	path_complete = ft_strjoin(path_tmp, cmd);
	free(path_tmp);
	path_tmp = NULL;
	return (path_complete);
}

char	*ft_get_path(char **envp, char *cmd)
{
	char	**dir;
	char	*path_complete;
	int		i;

	if (!cmd || !envp || !*envp)
		return (NULL);
	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		return (NULL);
	i = -1;
	dir = ft_split((*envp) + 5, ':');
	path_complete = NULL;
	while (dir && dir[++i])
	{
		path_complete = ft_join_path(dir[i], cmd);
			if (!path_complete || access(path_complete, X_OK) == 0)
		break ;
		free(path_complete);
		path_complete = NULL;
	}
	ft_free_matriz(dir);
	return (path_complete);
}
