/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:51:16 by icseri            #+#    #+#             */
/*   Updated: 2024/05/11 15:56:36 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_clist **stack_a, t_clist **stack_b)
{
	t_clist	*current;
	t_clist	*next;
	t_clist	*previous;

	current = *stack_a;
	next = current->next;
	previous = current->previous;

	if (current->rank > next->rank && current->rank > previous->rank)
		exec_rule(stack_a, stack_b, "ra\n", false);
	if (current->rank > next->rank)
		exec_rule(stack_a, stack_b, "sa\n", false);
	if (current->rank > previous->rank && next->rank > previous->rank)
		exec_rule(stack_a, stack_b, "rra\n", false);
}

void	indexing(t_clist **stack, int count)
{
	t_clist	*forward;
	t_clist	*backward;
	int		loopcount;

	loopcount = 0;
	forward = *stack;
	backward = *stack;
	while (loopcount < count)
	{
		forward->r_index = loopcount;
		backward->rr_index = loopcount;
		forward = forward->next;
		backward = backward->previous;
		loopcount++;
	}
}

void	set_price(t_clist *node_a, t_clist *node_b)
{
	int	rr;
	int	rrr;
	int	ra_rrb;
	int	rra_rb;
	int	price;

	rr = get_max(node_a->r_index, node_b->r_index);
	rrr = get_max(node_a->rr_index, node_b->rr_index);
	ra_rrb = node_a->r_index + node_b->rr_index;
	rra_rb = node_a->rr_index + node_b->r_index;
	price = get_min(get_min(rr, rrr), get_min(ra_rrb, rra_rb));
	node_a->price = price;
	node_b->price = price;
}

void	rotate_to_push(t_clist **a, t_clist **b, t_clist *n_a, t_clist *n_b)
{
	if (get_max(n_a->r_index, n_b->r_index) == n_a->price)
	{
		while (n_a->r_index > 0 && n_b->r_index > 0)
		{
			exec_rule(a, b, "rr\n", false);
			n_a->r_index--;
			n_b->r_index--;
		}
		while (n_a->r_index-- > 0)
			exec_rule(a, b, "ra\n", false);
		while (n_b->r_index-- > 0)
			exec_rule(a, b, "rb\n", false);
	}
	else if (get_max(n_a->rr_index, n_b->rr_index) == n_a->price)
	{
		while (n_a->rr_index > 0 && n_b->rr_index > 0)
		{
			exec_rule(a, b, "rrr\n", false);
			n_a->rr_index--;
			n_b->rr_index--;
		}
		while (n_a->rr_index-- > 0)
			exec_rule(a, b, "rra\n", false);
		while (n_b->rr_index-- > 0)
			exec_rule(a, b, "rrb\n", false);
	}
	else if (n_a->r_index + n_b->rr_index == n_a->price)
	{
		while (n_a->r_index-- > 0)
			exec_rule(a, b, "ra\n", false);
		while (n_b->rr_index-- > 0)
			exec_rule(a, b, "rrb\n", false);
	}
	else
	{
		while (n_a->rr_index-- > 0)
			exec_rule(a, b, "rra\n", false);
		while (n_b->r_index-- > 0)
			exec_rule(a, b, "rb\n", false);
	}
}

t_clist	*where_to_fit_in_b(int rank, t_clist **stack_b, int min, int max)
{
	t_clist	*current;

	current = *stack_b;
	if (rank < min || rank > max)
	{
		while (current->rank != max)
			current = current->next;
	}
	else
	{
		while (!(rank > current->rank && rank < current->previous->rank))
			current = current->next;
	}
	return (current);
}

void	rotate_to_pb(t_clist **stack_a, t_clist **stack_b, int min, int max)
{
	t_clist	*node_b;
	t_clist	*node_a;
	t_clist	*best_node_a;
	t_clist	*best_node_b;

	node_b = where_to_fit_in_b((*stack_a)->rank, stack_b, min, max);
	set_price(*stack_a, node_b);
	best_node_a = *stack_a;
	best_node_b = node_b;
	node_a = (*stack_a)->next;
	while (best_node_a->price > 0 && node_a != *stack_a)
	{
		node_b = where_to_fit_in_b(node_a->rank, stack_b, min, max);
		set_price(node_a, node_b);
		if (node_a->price < best_node_a->price)
		{
			best_node_a = node_a;
			best_node_b = node_b;
		}
		node_a = node_a->next;
	}
	set_price(best_node_a, best_node_b);
	rotate_to_push(stack_a, stack_b, best_node_a, best_node_b);
}

t_clist	*where_to_fit_in_a(int rank, t_clist **stack_a, int min, int max)
{
	t_clist	*current;

	current = *stack_a;
	if (rank < min || rank > max)
	{
		while (current->rank != min)
			current = current->next;
	}
	else
	{
		while (!(rank < current->rank && rank > current->previous->rank))
			current = current->next;
	}
	return (current);
}

void	rotate_to_pa(t_clist **stack_a, t_clist **stack_b, int min, int max)
{
	t_clist	*node_a;
	t_clist	*node_b;
	t_clist	*best_node_a;
	t_clist	*best_node_b;

	node_a = where_to_fit_in_a((*stack_b)->rank, stack_a, min, max);
	set_price(node_a, *stack_b);
	best_node_a = node_a;
	best_node_b = *stack_b;
	node_b = (*stack_b)->next;
	while (best_node_b->price > 0 && node_b != *stack_b)
	{
		node_a = where_to_fit_in_a(node_b->rank, stack_a, min, max);
		set_price(node_a, node_b);
		if (node_b->price < best_node_b->price)
		{
			best_node_a = node_a;
			best_node_b = node_b;
		}
		node_b = node_b->next;
	}
	set_price(best_node_a, best_node_b);
	rotate_to_push(stack_a, stack_b, best_node_a, best_node_b);
}

void	sort_push_b(t_clist **stack_a, t_clist **stack_b, int count)
{
	int	min;
	int	max;
	int	count_a;

	count_a = count;
	if (count_a-- >= 5)
		exec_rule(stack_a, stack_b, "pb\n", false);
	exec_rule(stack_a, stack_b, "pb\n", false);
	min = get_min((*stack_b)->rank, (*stack_b)->previous->rank);
	max = get_max((*stack_b)->rank, (*stack_b)->previous->rank);
	while (--count_a > 3)
	{
		indexing(stack_a, count_a);
		indexing(stack_b, count - count_a);
		rotate_to_pb(stack_a, stack_b, min, max);
		exec_rule(stack_a, stack_b, "pb\n", false);
		min = get_min((*stack_b)->rank, min);
		max = get_max((*stack_b)->rank, max);
	}
}

void	final_sort(t_clist **stack_a, t_clist **stack_b, int min, int max)
{
	t_clist	*head;

	head = where_to_fit_in_a(0, stack_a, min, max);
	if (head->r_index < head->rr_index)
	{
		while (head->r_index-- > 0)
			exec_rule(stack_a, stack_b, "ra\n", false);
	}
	else
	{
		while (head->rr_index-- > 0)
			exec_rule(stack_a, stack_b, "rra\n", false);
	}
}

void	sort_push_a(t_clist **stack_a, t_clist **stack_b, int count)
{
	int	min;
	int	max;
	int	count_a;

	count_a = ft_circ_lstsize(stack_a);
	min = (*stack_a)->rank;
	max = (*stack_a)->previous->rank;
	while (count_a != count)
	{
		indexing(stack_b, count - count_a);
		indexing(stack_a, count_a++);
		rotate_to_pa(stack_a, stack_b, min, max);
		exec_rule(stack_a, stack_b, "pa\n", false);
		min = get_min((*stack_a)->rank, min);
		max = get_max((*stack_a)->rank, max);
	}
	indexing(stack_a, count);
	final_sort(stack_a, stack_b, min, max);
}

int	sort(t_clist **stack_a, int count)
{
	t_clist	**stack_b;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		return (-1);
	*stack_b = NULL;
	if (count > 3)
		sort_push_b(stack_a, stack_b, count);
	if (is_sorted(stack_a) == false)
		mini_sort(stack_a, stack_b);
	if (*stack_b)
		sort_push_a(stack_a, stack_b, count);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	if (is_sorted(stack_a) == false)
		return (-1);
	return (1);
}
