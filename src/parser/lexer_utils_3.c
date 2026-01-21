/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:47:37 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/21 18:57:52 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	read_condition(char *out, char **part, const char *str, int *i)
{
	char	quote;

	if (is_quote(str[*i]))
	{
		quote = str[*i];
		(*i)++;
		*part = read_quoted(str, i, quote);
		if (*part == NULL)
		{
			free(out);
			return (1);
		}
	}
	else
	{
		*part = read_unquoted(str, i);
		if (*part == NULL)
		{
			free(out);
			return (1);
		}
	}
	return (0);
}

char	*read_word(const char *str, int *i)
{
	char	*out;
	char	*part;

	out = ft_strdup("");
	if (!out)
		return (NULL);
	while (str[*i] != '\0' && !is_space(str[*i]) && !is_metachar(str[*i]))
	{
		if (read_condition(out, &part, str, i))
			return (NULL);
		out = str_join_free(out, part);
		if (out == NULL)
			return (NULL);
	}
	return (out);
}

int	is_metachar(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

static t_toktype	condition_get_op(const char *str, int *i)
{
	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
		{
			(*i)++;
			(*i)++;
			return (T_REDIR_APP);
		}
		else
		{
			(*i)++;
			return (T_REDIR_OUT);
		}
	}
	return (T_WORD);
}

t_toktype	get_op_type(const char *str, int *i)
{
	t_toktype	toketype;

	if (str[*i] == '|')
	{
		(*i)++;
		return (T_PIPE);
	}
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
		{
			(*i)++;
			(*i)++;
			return (T_HEREDOC);
		}
		else
		{
			(*i)++;
			return (T_REDIR_IN);
		}
	}
	toketype = condition_get_op(str, i);
	return (toketype);
}
