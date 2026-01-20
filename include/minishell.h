/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:01:41 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/20 20:37:49 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_cmd
{
	char			**argv;
	struct s_redir	*redirs;
	struct s_cmd	*next;
}	t_cmd;

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
int		is_space(char c);
void	skip_spaces(const char *str, int *i);
int		is_quote(char c);
t_token	*token_new(t_toktype type, char *value);
void	token_add_back(t_token **lst, t_token *node);

// lexer_utils_2.c
char	*read_unquoted(const char *str, int *i);
char	*read_quoted(const char *str, int *i, char quote);
char	*str_join_free(char *a, char *b);
void	token_free_all(t_token *lst);
void	token_free_all(t_token *lst);

// lexer_utils_3.c
char	*read_word(const char *str, int *i);

// lexer.c
t_token	*lexer(const char *line);

// execute.c 
int		ft_execute(t_cmd *cmd, char **envp);

// exec_single.c 
int		ft_exec_single(t_cmd *cmd, char **envp);

// exec_pipeline.c 
int		ft_exec_pipeline(t_cmd *cmd, char **envp);

// path_utils.c 
char	*ft_join_path(char *dir, char *cmd);
char	*ft_get_path(char **envp, char *cmd);

// free.c 
void	ft_free_matriz(char **matriz);

#endif