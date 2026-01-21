/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:43:11 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/21 18:59:15 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	f_c_lexer(t_token **tokens, const char *line, int *i)
{
	t_toktype	type;
	t_token		*node;

	type = get_op_type(line, i);
	node = token_new(type, NULL);
	if (node == NULL)
	{
		token_free_all(*tokens);
		return (1);
	}
	token_add_back(tokens, node);
	return (0);
}

static int	s_c_lexer(t_token **tokens, const char *line, int *i)
{
	t_token		*node;
	char		*word;

	word = read_word(line, i);
	if (word == NULL)
	{
		token_free_all(*tokens);
		return (1);
	}
	node = token_new(T_WORD, word);
	if (node == NULL)
	{
		free(word);
		token_free_all(*tokens);
		return (1);
	}
	token_add_back(tokens, node);
	return (0);
}

t_token	*lexer(const char *line)
{
	t_token		*tokens;
	int			i;

	i = 0;
	tokens = NULL;
	while (line && line[i])
	{
		skip_spaces(line, &i);
		if (line[i] == '\0')
			break ;
		if (is_metachar(line[i]))
		{
			if (f_c_lexer(&tokens, line, &i))
				return (NULL);
		}
		else
		{
			if (s_c_lexer(&tokens, line, &i))
				return (NULL);
		}
	}
	return (tokens);
}
