/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:15:41 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/21 20:26:59 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_env(t_cmd *cmd, char **envp)
{
	if (!envp || !cmd || !cmd->argv)
		return (0);
	if (cmd->argv[1])
		return (0);
	while (*envp)
	{
		write(1, *envp, (int) ft_strlen(*envp));
		write(1, "\n", 1);
		envp++;
	}
	return (0);
}
