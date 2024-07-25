/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:11:45 by icseri            #+#    #+#             */
/*   Updated: 2024/07/25 15:03:28 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*where_to_fit_in_b(int rank, t_var *vars, int minimum, int maximum)
{
	t_clist	*current;

	current = *vars->stack_b;
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

void	rotate_to_pb(t_var *vars, int minimum, int maximum)
{
	t_clist	*node_b;
	t_clist	*node_a;
	t_clist	*best_node_a;
	t_clist	*best_node_b;

	node_b = where_to_fit_in_b((*vars->stack_a)->rank, vars, minimum, maximum);
	set_price(*vars->stack_a, node_b);
	best_node_a = *vars->stack_a;
	best_node_b = node_b;
	node_a = (*vars->stack_a)->next;
	while (best_node_a->price > 0 && node_a != *vars->stack_a)
	{
		node_b = where_to_fit_in_b(node_a->rank, vars, minimum, maximum);
		set_price(node_a, node_b);
		if (node_a->price < best_node_a->price)
		{
			best_node_a = node_a;
			best_node_b = node_b;
		}
		node_a = node_a->next;
	}
	set_price(best_node_a, best_node_b);
	rotate_to_push(vars, best_node_a, best_node_b);
}

void	sort_push_b(t_var *vars, int count)
{
	int	minimum;
	int	maximum;
	int	count_a;

	count_a = count;
	if (count_a-- >= 5)
		exec_rule(vars, "pb\n", false);
	exec_rule(vars, "pb\n", false);
	minimum = min(2, (*vars->stack_b)->rank, (*vars->stack_b)->previous->rank);
	maximum = max(2, (*vars->stack_b)->rank, (*vars->stack_b)->previous->rank);
	while (--count_a > 3)
	{
		set_rotate_index(vars->stack_a, count_a);
		set_rotate_index(vars->stack_b, count - count_a);
		rotate_to_pb(vars, minimum, maximum);
		exec_rule(vars, "pb\n", false);
		minimum = min(2, (*vars->stack_b)->rank, minimum);
		maximum = max(2, (*vars->stack_b)->rank, maximum);
	}
}
