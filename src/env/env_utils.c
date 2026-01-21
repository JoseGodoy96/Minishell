/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:38:59 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/21 19:19:45 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_env_get(char **envp, char *var)
{
	char	*variable;
	char	*p;

	p = ft_strjoin(var, "=");
	while (*envp && ft_strncmp(*envp, p, ft_strlen(p)) != 0)
		envp++;
	*envp = (*envp) + 1 + (int)ft_strlen(var);
	free(p);
	if (!*envp)
		return (NULL);
	variable = (char *) malloc(sizeof(char *) * ft_strlen(*envp) + 1);
	if (!variable)
		return (NULL);
	ft_strlcpy(variable, *envp, ft_strlen(*envp) + 1);
	return (variable);
}
