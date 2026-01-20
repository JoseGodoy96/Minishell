/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:01:41 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/19 12:52:05 by aarias-d         ###   ########.fr       */
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
} t_cmd;


/* - - - - - folder: executor - - - - - -*/
/* - - - - - file: execute.c - - - - - -*/
int	ft_execute(t_cmd *cmd, char **envp);
/* - - - - - file: exec_single.c - - - - - -*/
int	ft_exec_single(t_cmd *cmd, char **envp);
/* - - - - - file: exec_pipeline.c - - - - - -*/
int ft_exec_pipeline(t_cmd *cmd, char **envp );
/* - - - - - file: path_utils.c - - - - - -*/
char	*ft_join_path(char *dir, char *cmd);
char	*ft_get_path(char **envp, char *cmd);

/* - - - - - folder: utils - - - - - -*/
/* - - - - - file: free.c - - - - - -*/
void	ft_free_matriz(char **matriz);


#endif