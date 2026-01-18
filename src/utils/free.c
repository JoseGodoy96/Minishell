/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:47:38 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/18 20:48:12 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_matriz(char **matriz)
{
	int	i;

	if (!matriz)
		return ;
	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}
