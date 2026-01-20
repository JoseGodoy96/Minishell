/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:22:28 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/20 19:16:02 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_execute(t_cmd *cmd, char **envp)
{
	if(!cmd->next)
		return(ft_exec_single(cmd, envp));
	return (1);
}
