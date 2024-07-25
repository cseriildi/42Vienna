/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:03:51 by icseri            #+#    #+#             */
/*   Updated: 2024/07/25 15:06:32 by icseri           ###   ########.fr       */
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
		*arr = NULL;
	}
}

void	free_all(t_var *vars)
{
	if (!vars)
		return ;
	if (vars->stack_a)
	{
		ft_circ_lstclear(vars->stack_a);
		free(vars->stack_a);
		vars->stack_a = NULL;
	}
	if (vars->stack_b)
	{
		ft_circ_lstclear(vars->stack_b);
		free(vars->stack_b);
		vars->stack_b = NULL;
	}
	if (vars->nums)
		array_free(&vars->nums);
	if (vars->numbers)
		ft_free((void **)&vars->numbers);
	if (vars->ranks)
		ft_free((void **)&vars->ranks);
	free(vars);
}

void	error(t_var *vars)
{
	free_all(vars);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}
