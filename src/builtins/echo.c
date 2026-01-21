/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 21:20:53 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/21 21:46:41 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_echo(t_cmd *cmd)
{
	int	i;

	if (!cmd || !cmd->argv)
		return (1);
	i = 1;
	while (cmd->argv[i])
	{
		write(1, cmd->argv[i], ft_strlen(cmd->argv[i]));
		i++;
		if (cmd->argv[i])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
