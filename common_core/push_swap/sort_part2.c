/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:11:45 by icseri            #+#    #+#             */
/*   Updated: 2024/07/25 15:02:12 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*where_to_fit_in_a(int rank, t_var *vars, int minimum, int maximum)
{
	t_clist	*current;

	current = *vars->stack_a;
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

void	rotate_to_pa(t_var *vars, int minimum, int maximum)
{
	t_clist	*node_a;
	t_clist	*node_b;
	t_clist	*best_node_a;
	t_clist	*best_node_b;

	node_a = where_to_fit_in_a((*vars->stack_b)->rank, vars, minimum, maximum);
	set_price(node_a, *vars->stack_b);
	best_node_a = node_a;
	best_node_b = *vars->stack_b;
	node_b = (*vars->stack_b)->next;
	while (best_node_b->price > 0 && node_b != *vars->stack_b)
	{
		node_a = where_to_fit_in_a(node_b->rank, vars, minimum, maximum);
		set_price(node_a, node_b);
		if (node_b->price < best_node_b->price)
		{
			best_node_a = node_a;
			best_node_b = node_b;
		}
		node_b = node_b->next;
	}
	set_price(best_node_a, best_node_b);
	rotate_to_push(vars, best_node_a, best_node_b);
}

void	final_sort(t_var *vars, int minimum, int maximum)
{
	t_clist	*head;

	head = where_to_fit_in_a(0, vars, minimum, maximum);
	if (head->r_index < head->rr_index)
		repeat_rule(vars, head->r_index, "ra\n");
	else
		repeat_rule(vars, head->rr_index, "rra\n");
}

void	sort_push_a(t_var *vars, int count)
{
	int	minimum;
	int	maximum;
	int	count_a;

	count_a = 3;
	minimum = (*vars->stack_a)->rank;
	maximum = (*vars->stack_a)->previous->rank;
	while (count_a != count)
	{
		set_rotate_index(vars->stack_b, count - count_a);
		set_rotate_index(vars->stack_a, count_a++);
		rotate_to_pa(vars, minimum, maximum);
		exec_rule(vars, "pa\n", false);
		minimum = min(2, (*vars->stack_a)->rank, minimum);
		maximum = max(2, (*vars->stack_a)->rank, maximum);
	}
	set_rotate_index(vars->stack_a, count);
	final_sort(vars, minimum, maximum);
}
