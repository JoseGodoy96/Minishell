/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:43:11 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/20 18:09:12 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	f_c_lexer(t_token *tokens, char *word)
{
	if (word == NULL)
	{
		token_free_all(tokens);
		return (1);
	}
	return (0);
}

static int	s_c_lexer(t_token *tokens, t_token *node, char *word)
{
	if (node == NULL)
	{
		free(word);
		token_free_all(tokens);
		return (1);
	}
	return (0);
}

t_token	*lexer(const char *line)
{
	t_token	*tokens;
	t_token	*node;
	char	*word;
	int		i;

	i = 0;
	tokens = NULL;
	while (line && line[i])
	{
		skip_spaces(line, &i);
		if (line[i] == '\0')
			break ;
		word = read_word(line, &i);
		if (f_c_lexer(tokens, word))
			return (NULL);
		node = token_new(T_WORD, word);
		if (s_c_lexer(tokens, node, word))
			return (NULL);
		token_add_back(&tokens, node);
	}
	return (tokens);
}
