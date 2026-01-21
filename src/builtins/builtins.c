/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:55:11 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/21 20:48:53 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(char *cmd)
{
	while (is_space(*cmd) == 1|| *cmd == '\0')
		cmd++;
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}

int	ft_exec_builtins(t_cmd *cmd, char **envp)
{
	while (is_space(*cmd->argv[0]) == 1 || *cmd->argv[0] == '\0')
		cmd++;
	if (ft_strncmp(cmd->argv[0], "cd", 3) == 0)
		return (ft_exec_cd(cmd, envp));
	if (ft_strncmp(cmd->argv[0], "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd->argv[0], "pwd", 4) == 0)
		return (ft_exec_pwd(cmd, envp));
	if (ft_strncmp(cmd->argv[0], "env", 4) == 0)
		return (ft_exec_env(cmd, envp));
	if (ft_strncmp(cmd->argv[0], "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd->argv[0], "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd->argv[0], "exit", 5) == 0)
		return (1);
	return (0);
}