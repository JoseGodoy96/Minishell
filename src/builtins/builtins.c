/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:55:11 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/20 21:06:33 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "cd", 3))
		return (1);
	if (ft_strncmp(cmd, "echo", 5))
		return (1);
	if (ft_strncmp(cmd, "pwd", 4))
		return (1);
	if (ft_strncmp(cmd, "env", 4))
		return (1);
	if (ft_strncmp(cmd, "export", 7))
		return (1);
	if (ft_strncmp(cmd, "unset", 6))
		return (1);
	if (ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

