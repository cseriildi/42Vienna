/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:10:23 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/11 15:37:21 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ranks(int count, char **params, int *numbers, int *ranks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count)
		numbers[i] = ft_atoi(params[i]);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (numbers[i] >= numbers[j++])
				ranks[i] += 1;
		}
		i++;
	}
}

t_clist	**create_stack(int count, char **params)
{
	t_clist	**stack_a;
	t_clist	*current;
	int		*numbers;
	int		*ranks;

	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	ranks = ft_calloc(sizeof(int), count);
	if (!ranks)
		return (free(numbers), NULL);
	get_ranks(count, params, numbers, ranks);
	stack_a = malloc(sizeof(t_clist *));
	if (!stack_a)
		return (free(numbers), free(ranks), NULL);
	*stack_a = NULL;
	while (--count >= 0)
	{
		current = ft_circ_lstnew(numbers[count], ranks[count]);
		if (!current)
			return (ft_circ_lstclear(stack_a), free(stack_a), NULL);
		ft_circ_lstadd_front(stack_a, current);
	}
	return (free(numbers), free(ranks), stack_a);
}
