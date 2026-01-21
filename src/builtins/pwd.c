/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:04:58 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/21 20:52:03 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	ft_exec_pwd(t_cmd *cmd, char **envp)
{
	char	*pwd;

	if (!envp || !cmd || !cmd->argv)
		return (0);
	if (!cmd->argv[1])
	{
		pwd = ft_env_get(envp, "PWD");
		write(1, pwd, ft_strlen(pwd) + 1);
		write(1, "\n", 1);
		free(pwd);
		return (0);
	}
	return (1);
}
