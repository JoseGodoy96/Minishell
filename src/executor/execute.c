/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:22:28 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/18 20:06:30 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_free_matriz(char **matriz)
{
	int	i;

	if (!matriz)
		return ;
	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

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

int	execute(t_cmd *cmd, char **envp)
{
	char	*path;

	if (!cmd->argv)
	{
		write(2, "Error command\n", 14);
		return (1);
	}
	path = ft_get_path(envp, cmd->argv[0]);
	if (!path)
	{
		write(2, "Command not found\n", 18);
		return (1);
	}
	execve(path, cmd->argv, envp);
	free(path);
	perror("Execve");
    return (1);
}