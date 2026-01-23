/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:26:23 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/21 20:52:07 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*redir_new(t_toktype type, const char *target)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(*redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->target = ft_strdup(target);
	if (!redir->target)
	{
		free(redir);
		return (NULL);
	}
	redir->next = NULL;
	return (redir);
}

void	redir_add_back(t_redir **lst, t_redir *node)
{
	t_redir	*temp;

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

void	redir_free_all(t_redir *redir)
{
	t_redir	*temp;

	if (!redir)
		return ;
	while (redir != NULL)
	{
		temp = redir->next;
		free(redir->target);
		free(redir);
		redir = temp;
	}
}
