/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:51:16 by icseri            #+#    #+#             */
/*   Updated: 2024/05/08 12:31:12 by icseri           ###   ########.fr       */
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

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	rotate_b_to(t_clist **stack_a, t_clist **stack_b, int min, int max, int count_b)
{
	t_clist	*head;
	t_clist *current;
	int	loopcount;
	char	*rule;

	head = *stack_b;
	current = *stack_b;
	loopcount = 0;
	if ((*stack_a)->rank < min || (*stack_a)->rank > max)
	{
		while (current->rank != max)
		{
			current = current->next;
			loopcount++;
		}
		while (current != head)
			current = current->next;
		if (loopcount < count_b / 2)
			rule = "rb\n";
		else
			rule = "rrb\n";
		while ((*stack_b)->rank != max)
				sorting(stack_a, stack_b, rule);
			min = get_min((*stack_b)->rank, min);
			max = get_max((*stack_b)->rank, max);
		
	}
	else
	{
		while ((*stack_a)->rank < current->rank ||
			(*stack_a)->rank > current->previous->rank)
		{
			current = current->next;
			loopcount++;
		}
		while (current != head)
			current = current->next;
		if (loopcount < count_b / 2)
			rule = "rb\n";
		else
			rule = "rrb\n";
		while ((*stack_a)->rank < (*stack_b)->rank ||
			(*stack_a)->rank > (*stack_b)->previous->rank)
			sorting(stack_a, stack_b, rule);
	}
}

void	sort_push_b(t_clist **stack_a, t_clist **stack_b, int count)
{
	int	min;
	int	max;
	int	count_a;

	sorting(stack_a, stack_b, "pb\n");
	sorting(stack_a, stack_b, "pb\n");
	count_a = count - 2;
	min = get_min((*stack_b)->rank, (*stack_b)->next->rank);
	max = get_max((*stack_b)->rank, (*stack_b)->next->rank);
	while (count_a > 3)	
	{
		rotate_b_to(stack_a, stack_b, min, max, count - count_a);
		sorting(stack_a, stack_b, "pb\n");
		count_a--;
	}
}

void	rotate_a_to(t_clist **stack_a, t_clist **stack_b, int min, int max, int count_a)
{
	t_clist	*head;
	t_clist *current;
	int	loopcount;
	char	*rule;

	head = *stack_a;
	current = *stack_a;
	loopcount = 0;
	if ((*stack_b)->rank < min || (*stack_b)->rank > max)
	{
		while (current->rank != min)
		{
			current = current->next;
			loopcount++;
		}
		while (current != head)
			current = current->next;
		if (loopcount < count_a / 2)
			rule = "ra\n";
		else
			rule = "rra\n";
		while ((*stack_a)->rank != min)
			sorting(stack_a, stack_b, rule);
		min = get_min((*stack_a)->rank, min);
		max = get_max((*stack_a)->rank, max);
	}
	else
	{
		while ((*stack_b)->rank > current->rank ||
			(*stack_b)->rank < current->previous->rank)
		{
			current = current->next;
			loopcount++;
		}
		while (current != head)
			current = current->next;
		if (loopcount < count_a / 2)
			rule = "ra\n";
		else
			rule = "rra\n";
		while ((*stack_b)->rank > (*stack_a)->rank ||
			(*stack_b)->rank < (*stack_a)->previous->rank)
				sorting(stack_a, stack_b, rule);
	}
}

void	sort_push_a(t_clist **stack_a, t_clist **stack_b)
{
	int min;
	int max;
	int	count_a;
	
	min = (*stack_a)->rank;
	max = (*stack_a)->previous->rank;
	count_a = 3;
	while (*stack_b != NULL)
	{
		rotate_a_to(stack_a, stack_b, min, max, count_a);
		sorting(stack_a, stack_b, "pa\n");
		count_a++;
	}
}

int	push_swap(t_clist **stack_a, int count)
{
	t_clist	**stack_b;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		return (ft_circ_lstclear(stack_a), free(stack_a), -1);
	*stack_b = NULL;
	if (count <= 3)
		mini_sort(stack_a, stack_b, count);
	sort_push_b(stack_a, stack_b, count);
	if (!check_if_sorted(stack_a, 1))
		mini_sort(stack_a, stack_b, count);
	sort_push_a(stack_a, stack_b);
	ft_circ_lstclear(stack_a);
	free(stack_a);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	return (1);
}
