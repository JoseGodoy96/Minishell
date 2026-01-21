/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:42:24 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/21 19:57:19 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_cd(t_cmd *cmd, char **envp)
{
	int		status;
	char	*home;

	if (!envp || !cmd || !cmd->argv)
		return (0);
	if (!cmd->argv[1])
	{
		home = ft_env_get(envp, "HOME");
		status = chdir(home);
		free(home);
	}
	else
		status = chdir(cmd->argv[1]);
	if (status == 0)
		return (0);
	perror("cd");
	return (1);
}
