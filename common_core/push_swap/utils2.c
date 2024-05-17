/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:03:51 by icseri            #+#    #+#             */
/*   Updated: 2024/05/17 10:13:11 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

void	array_free(char ***arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while ((*arr)[i])
			free((*arr)[i++]);
		free(*arr);
	}
}

void	malloc_failed(t_clist **stack_a, char **arr, void *p1, void *p2)
{
	if (stack_a)
	{
		ft_circ_lstclear(stack_a);
		free(stack_a);
	}
	array_free(&arr);
	ft_free(&p1);
	ft_free(&p2);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}
