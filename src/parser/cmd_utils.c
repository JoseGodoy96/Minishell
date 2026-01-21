/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:47:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/21 20:26:32 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(*cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->argv = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	cmd_add_back(t_cmd **lst, t_cmd *node)
{
	t_cmd	*temp;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
}

void	cmd_free_one(t_cmd *cmd)
{
	if (cmd)
		return ;
	ft_free_matriz(cmd->argv);
	redir_free_all(cmd->redirs);
	free(cmd);
}

void	cmd_free_all(t_cmd *cmds)
{
	t_cmd	*temp;

	while (cmds != NULL)
	{
		temp = cmds->next;
		cmd_free_one(cmds);
		cmds = temp;
	}
}
