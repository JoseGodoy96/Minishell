/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:05:11 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/23 20:45:50 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_strnode	*strnode_new(const char *s)
{
	t_strnode	*str_node;

	str_node = (t_strnode *)malloc(sizeof(*str_node));
	if (!str_node)
		return (NULL);
	str_node->s = ft_strdup(s);
	str_node->next = NULL;
	if (!str_node->s)
	{
		free(str_node);
		return (NULL);
	}
	return (str_node);
}

void	strnode_add_back(t_strnode **lst, t_strnode *node)
{
	t_strnode	*temp;

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

int	strlist_size(t_strnode *lst)
{
	int			i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	**strlist_to_argv(t_strnode *lst)
{
	char	**matrix;
	int		i;

	matrix = (char **)malloc(sizeof(char *) * (strlist_size(lst) + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (lst != NULL)
	{
		matrix[i] = ft_strdup(lst->s);
		matrix[i + 1] = NULL;
		if (!matrix[i])
		{
			ft_free_matriz(matrix);
			return (NULL);
		}
		i++;
		lst = lst->next;
	}
	return (matrix);
}

void	strlist_free_all(t_strnode *lst)
{
	t_strnode	*temp;

	if (!lst)
		return ;
	while (lst != NULL)
	{
		temp = lst->next;
		free(lst->s);
		free(lst);
		lst = temp;
	}
}
