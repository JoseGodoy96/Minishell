/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:47:37 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/18 21:54:05 by jgodoy-m         ###   ########.fr       */
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
	while (str[*i] != '\0' && !is_space(str[*i]))
	{
		if (read_condition(out, &part, str, i))
			return (NULL);
		out = str_join_free(out, part);
		if (out == NULL)
			return (NULL);
	}
	return (out);
}
