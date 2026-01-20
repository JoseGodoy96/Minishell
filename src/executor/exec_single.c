/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:04:22 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/20 19:15:39 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_child_execute(char *path, char **cmd, char **envp)
{
	if (!path)
	{
		perror("Command not found");
		ft_free_matriz(cmd);
		free(path);
		exit (127);
	}
	execve(path, cmd, envp);
	ft_free_matriz(cmd);
	free(path);
	perror("Execve");
	exit (1);
}

int	ft_exec_single(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	char	*path;
	int		status;

	if (!cmd || !cmd->argv || !cmd->argv[0])
	{
		write(2, "Error command\n", 14);
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		write(2, "Error fork\n", 11);
		return (1);
	}
	path = ft_get_path(envp, cmd->argv[0]);
	if (pid == 0)
		ft_child_execute(path, cmd->argv, envp);
	free(path);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return(128 + WTERMSIG(status));
	return (1);
}
