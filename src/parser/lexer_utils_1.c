/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:46:24 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/20 17:51:26 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

void	skip_spaces(const char *str, int *i)
{
	while (str[*i] != '\0')
	{
		if (is_space(str[*i]))
			(*i)++;
		else
			break ;
	}
}

int	is_quote(char c)
{
	if (c == 39 || c == 34)
		return (1);
	return (0);
}

t_token	*token_new(t_toktype type, char *value)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->type = type;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	token_add_back(t_token **lst, t_token *node)
{
	t_token	*temp;

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
