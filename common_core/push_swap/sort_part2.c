/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:11:45 by icseri            #+#    #+#             */
/*   Updated: 2024/05/12 08:15:21 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*where_to_fit_in_a(int rank, t_clist **a, int minimum, int maximum)
{
	t_clist	*current;

	current = *a;
	if (rank < minimum || rank > maximum)
	{
		while (current->rank != minimum)
			current = current->next;
	}
	else
	{
		while (!(rank < current->rank && rank > current->previous->rank))
			current = current->next;
	}
	return (current);
}

void	rotate_to_pa(t_clist **a, t_clist **b, int minimum, int maximum)
{
	t_clist	*node_a;
	t_clist	*node_b;
	t_clist	*best_node_a;
	t_clist	*best_node_b;

	node_a = where_to_fit_in_a((*b)->rank, a, minimum, maximum);
	set_price(node_a, *b);
	best_node_a = node_a;
	best_node_b = *b;
	node_b = (*b)->next;
	while (best_node_b->price > 0 && node_b != *b)
	{
		node_a = where_to_fit_in_a(node_b->rank, a, minimum, maximum);
		set_price(node_a, node_b);
		if (node_b->price < best_node_b->price)
		{
			best_node_a = node_a;
			best_node_b = node_b;
		}
		node_b = node_b->next;
	}
	set_price(best_node_a, best_node_b);
	rotate_to_push(a, b, best_node_a, best_node_b);
}

void	final_sort(t_clist **a, int minimum, int maximum)
{
	t_clist	*head;

	head = where_to_fit_in_a(0, a, minimum, maximum);
	if (head->r_index < head->rr_index)
		repeat_rule(a, NULL, head->r_index, "ra\n");
	else
		repeat_rule(a, NULL, head->rr_index, "rra\n");
}

void	sort_push_a(t_clist **a, t_clist **b, int count)
{
	int	minimum;
	int	maximum;
	int	count_a;

	count_a = 3;
	minimum = (*a)->rank;
	maximum = (*a)->previous->rank;
	while (count_a != count)
	{
		set_rotate_index(b, count - count_a);
		set_rotate_index(a, count_a++);
		rotate_to_pa(a, b, minimum, maximum);
		exec_rule(a, b, "pa\n", false);
		minimum = min(2, (*a)->rank, minimum);
		maximum = max(2, (*a)->rank, maximum);
	}
	set_rotate_index(a, count);
	final_sort(a, minimum, maximum);
}
