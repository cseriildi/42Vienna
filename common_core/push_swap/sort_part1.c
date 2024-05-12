/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:11:45 by icseri            #+#    #+#             */
/*   Updated: 2024/05/12 07:48:26 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*where_to_fit_in_b(int rank, t_clist **b, int minimum, int maximum)
{
	t_clist	*current;

	current = *b;
	if (rank < minimum || rank > maximum)
	{
		while (current->rank != maximum)
			current = current->next;
	}
	else
	{
		while (!(rank > current->rank && rank < current->previous->rank))
			current = current->next;
	}
	return (current);
}

void	rotate_to_pb(t_clist **a, t_clist **b, int minimum, int maximum)
{
	t_clist	*node_b;
	t_clist	*node_a;
	t_clist	*best_node_a;
	t_clist	*best_node_b;

	node_b = where_to_fit_in_b((*a)->rank, b, minimum, maximum);
	set_price(*a, node_b);
	best_node_a = *a;
	best_node_b = node_b;
	node_a = (*a)->next;
	while (best_node_a->price > 0 && node_a != *a)
	{
		node_b = where_to_fit_in_b(node_a->rank, b, minimum, maximum);
		set_price(node_a, node_b);
		if (node_a->price < best_node_a->price)
		{
			best_node_a = node_a;
			best_node_b = node_b;
		}
		node_a = node_a->next;
	}
	set_price(best_node_a, best_node_b);
	rotate_to_push(a, b, best_node_a, best_node_b);
}

void	sort_push_b(t_clist **a, t_clist **b, int count)
{
	int	minimum;
	int	maximum;
	int	count_a;

	count_a = count;
	if (count_a-- >= 5)
		exec_rule(a, b, "pb\n", false);
	exec_rule(a, b, "pb\n", false);
	minimum = min(2, (*b)->rank, (*b)->previous->rank);
	maximum = max(2, (*b)->rank, (*b)->previous->rank);
	while (--count_a > 3)
	{
		set_rotate_index(a, count_a);
		set_rotate_index(b, count - count_a);
		rotate_to_pb(a, b, minimum, maximum);
		exec_rule(a, b, "pb\n", false);
		minimum = min(2, (*b)->rank, minimum);
		maximum = max(2, (*b)->rank, maximum);
	}
}
