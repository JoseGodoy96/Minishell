/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:01:41 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/20 20:13:00 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef enum e_toktype
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APP,
	T_HEREDOC
}	t_toktype;

typedef struct s_token
{
	t_toktype		type;
	char			*value;
	struct s_token	*next;
}	t_token;

// lexer_utils_1.c
int			is_space(char c);
void		skip_spaces(const char *str, int *i);
int			is_quote(char c);
t_token		*token_new(t_toktype type, char *value);
void		token_add_back(t_token **lst, t_token *node);

// lexer_utils_2.c
char		*read_unquoted(const char *str, int *i);
char		*read_quoted(const char *str, int *i, char quote);
char		*str_join_free(char *a, char *b);
void		token_free_all(t_token *lst);
void		token_free_all(t_token *lst);

// lexer_utils_3.c
char		*read_word(const char *str, int *i);
int			is_metachar(char c);
t_toktype	get_op_type(const char *str, int *i);

// lexer.c
t_token		*lexer(const char *line);

#endif