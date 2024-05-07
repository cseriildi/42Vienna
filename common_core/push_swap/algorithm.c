/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:51:16 by icseri            #+#    #+#             */
/*   Updated: 2024/05/07 16:09:26 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_clist **stack_a, t_clist **stack_b, int count)
{
	if (count == 2)
		sorting(stack_a, stack_b, "sa\n");
	if (count == 3)
	{
		if ((*stack_a)->rank > (*stack_a)->next->rank)
		{
			if ((*stack_a)->rank < (*stack_a)->previous->rank)
				sorting(stack_a, stack_b, "sa\n"); // 2 1 3
			else if ((*stack_a)->previous->rank > (*stack_a)->next->rank)
				sorting(stack_a, stack_b, "ra\n"); // 3 1 2
			else
			{
				sorting(stack_a, stack_b, "sa\n"); // 3 2 1
				sorting(stack_a, stack_b, "rra\n");
			}
		}
		else
		{
			if ((*stack_a)->rank < (*stack_a)->previous->rank)
				sorting(stack_a, stack_b, "rra\n"); // 2 3 1
			else
			{
				sorting(stack_a, stack_b, "rra\n"); // 1 3 2
				sorting(stack_a, stack_b, "sa\n");
			}
		}
	}
}
void	rotate_to(t_clist **stack_a, t_clist **stack_b)
{
	
}


void	sort_push_b(t_clist **stack_a, t_clist **stack_b, int count)
{
	if (!*stack_b || (*stack_b)->next == *stack_b)
		sorting(stack_a, stack_b, "pb\n");
	else
	{

	}
}

int	push_swap(t_clist **stack_a, int count)
{
	t_clist	**stack_b;
	int		count_a;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		return (ft_circ_lstclear(stack_a), free(stack_a), -1);
	*stack_b = NULL;
	count_a = count;
	if (count_a <= 3)
		mini_sort(stack_a, stack_b, count);
	while (count_a > 3)
		sort_push_b(stack_a, stack_b);
	if (!check_if_sorted(stack_a, 1))
		sort_three(stack_a);
	sort_push_a(stack_a, stack_b);
	ft_circ_lstclear(stack_a);
	free(stack_a);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	return (1);
}
