/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:46:06 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/18 21:50:17 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_unquoted(const char *str, int *i)
{
	char	*new;
	int		start;

	start = *i;
	while (str[*i] != '\0')
	{
		if (!is_space(str[*i]) && !is_quote(str[*i]))
			(*i)++;
		else
		{
			new = ft_substr(str, start, *i - start);
			return (new);
		}
	}
	new = ft_substr(str, start, *i - start);
	return (new);
}

char	*read_quoted(const char *str, int *i, char quote)
{
	char	*new;
	int		start;

	start = *i;
	while (str[*i] != '\0')
	{
		if (str[*i] == quote)
		{
			new = ft_substr(str, start, *i - start);
			(*i)++;
			return (new);
		}
		(*i)++;
	}
	return (NULL);
}

static void	concat_into(char *new, char *a, char *b)
{
	int	i;
	int	j;

	i = 0;
	while (a[i] != '\0')
	{
		new[i] = a[i];
		i++;
	}
	j = 0;
	while (b[j] != '\0')
	{
		new[i + j] = b[j];
		j++;
	}
	new[i + j] = '\0';
	free(a);
	free(b);
}

char	*str_join_free(char *a, char *b)
{
	char	*new;

	if (!a || !b)
	{
		free(a);
		free(b);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1));
	if (!new)
	{
		free(a);
		free(b);
		return (NULL);
	}
	concat_into(new, a, b);
	return (new);
}

void	token_free_all(t_token *lst)
{
	t_token	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->value);
		free(lst);
		lst = tmp;
	}
}
