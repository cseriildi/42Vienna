/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:51:16 by icseri            #+#    #+#             */
/*   Updated: 2024/05/08 12:48:50 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_clist **stack_a, t_clist **stack_b)
{
	if ((*stack_a)->rank > (*stack_a)->next->rank &&
		(*stack_a)->rank > (*stack_a)->previous->rank)
		sorting(stack_a, stack_b, "ra\n");
	if ((*stack_a)->rank > (*stack_a)->next->rank)
		sorting(stack_a, stack_b, "sa\n");
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

void	indexing(t_clist **stack, int count)
{
	t_clist *current;
	int	r;
	int	rr;

	r = 0;
	rr = count;
	current = *stack;
	while (rr != 0)
	{
		current->r_index = r++;
		current = current->next;
		current->rr_index = --rr;
	}
}

void	set_price(t_clist *node_a, t_clist *node_b)
{
	int	rr;
	int rrr;
	int rarrb;
	int	rrarb;
	int price;

	rr = get_max(node_a->r_index, node_b->r_index);
	rrr = get_max(node_a->rr_index, node_b->rr_index);
	rarrb = node_a->r_index + node_b->rr_index;
	rrarb = node_a->rr_index + node_b->r_index;
	price = get_min(get_min(rr, rrr), get_min(rarrb, rrarb));
	node_a->price = price;
	node_b->price = price;
}

void	rotate_to_bests(t_clist **stack_a, t_clist **stack_b, t_clist *node_a, t_clist *node_b)
{
	if (get_max(node_a->r_index, node_b->r_index) == node_a->price)
	{
		while (node_a->r_index-- > 0 && node_b->r_index-- > 0)
			sorting(stack_a, stack_b, "rr\n");
		while (node_a->r_index-- > 0)
			sorting(stack_a, stack_b, "ra\n");
		while (node_b->r_index-- > 0)
			sorting(stack_a, stack_b, "rb\n");
	}
	else if (get_max(node_a->rr_index, node_b->rr_index) == node_a->price)
	{
		while (node_a->rr_index-- > 0 && node_b->rr_index-- > 0)
			sorting(stack_a, stack_b, "rrr\n");
		while (node_a->rr_index-- > 0)
			sorting(stack_a, stack_b, "rra\n");
		while (node_b->rr_index-- > 0)
			sorting(stack_a, stack_b, "rrb\n");
	}
	else if (node_a->r_index + node_b->rr_index == node_a->price)
	{
		while (node_a->r_index-- > 0)
			sorting(stack_a, stack_b, "ra\n");
		while (node_b->rr_index-- > 0)
			sorting(stack_a, stack_b, "rrb\n");
	}
	else
	{
		while (node_a->rr_index-- > 0)
			sorting(stack_a, stack_b, "rra\n");
		while (node_b->r_index-- > 0)
			sorting(stack_a, stack_b, "rb\n");
	}
}

t_clist	*where_to_fit_in_b(int rank, t_clist **stack_b, int min, int max)
{
	t_clist *current;

	current = *stack_b;
	while (!((rank < min || rank > max) && current->rank != max) &&
           !(rank < current->rank || rank > current->previous->rank)) {
        current = current->next;
    }
	return (current);
}

void	best_rotate_to_pb(t_clist **stack_a, t_clist **stack_b, int min, int max)
{
	t_clist	*node_b;
	t_clist	*node_a;
	t_clist	*best_node_a;
	t_clist	*best_node_b;

	node_b = where_to_fit_in_b((*stack_a)->rank, stack_b, min, max);
	set_price(*stack_a, node_b);
	best_node_a = *stack_a;
	best_node_b = *stack_b;
	node_a = (*stack_a)->next;
	while (best_node_a->price > 0 && node_a != *stack_a)
	{
		node_b = where_to_fit_in_b(node_a->rank, stack_b, min, max);
		set_price(node_a, node_b);
		if (node_b->price < best_node_b->price)
		{
			best_node_a = node_a;
			best_node_b = node_b;
		}
		node_a = node_a->next;
	}
	rotate_to_bests(stack_a, stack_b, best_node_a, best_node_b);
}


t_clist	*where_to_fit_in_a(int rank, t_clist **stack_a, int min, int max)
{
	t_clist *current;

	current = *stack_a;
	while (!((rank < min || rank > max) && current->rank != min) &&
           !(rank > current->rank || rank < current->previous->rank))
        current = current->next;
	return (current);
}

void	best_rotate_to_pa(t_clist **stack_a, t_clist **stack_b, int min, int max)
{
	t_clist	*node_a;
	t_clist	*node_b;
	t_clist	*best_node_a;
	t_clist	*best_node_b;

	node_a = where_to_fit_in_a((*stack_b)->rank, stack_a, min, max);
	set_price(node_a, *stack_b);
	node_b = (*stack_b)->next;
	best_node_a = node_a;
	best_node_b = (*stack_b);
	while (best_node_b->price > 0 && node_b != *stack_b)
	{
		node_a = where_to_fit_in_a(node_b->rank, stack_a, min, max);
		set_price(node_a, node_b);
		if (node_a->price < best_node_a->price)
		{
			best_node_a = node_a;
			best_node_b = node_b;
		}
		node_b = node_b->next;
	}
	rotate_to_bests(stack_a, stack_b, best_node_a, best_node_b);
}

void	sort_push_b(t_clist **stack_a, t_clist **stack_b, int count)
{
	int	min;
	int	max;
	int	count_a;

	count_a = count;
	if (count_a-- >= 5)
		sorting(stack_a, stack_b, "pb\n");
	sorting(stack_a, stack_b, "pb\n");
	min = get_min((*stack_b)->rank, (*stack_b)->next->rank);
	max = get_max((*stack_b)->rank, (*stack_b)->next->rank);
	while (--count_a > 3)	
	{
		indexing(stack_a, count_a);
		indexing(stack_b, count - count_a);
		best_rotate_to_pb(stack_a, stack_b, min, max);
		sorting(stack_a, stack_b, "pb\n");
		min = get_min((*stack_b)->rank, min);
		max = get_max((*stack_b)->rank, max);
	}
}

void	sort_push_a(t_clist **stack_a, t_clist **stack_b, int count)
{
	int	min;
	int	max;
	int	count_a;

	count_a = 3;
	min = (*stack_a)->rank;
	max = (*stack_a)->previous->rank;
	while (*stack_b)	
	{
		indexing(stack_b, count - count_a);
		indexing(stack_a, count_a++);
		best_rotate_to_pa(stack_a, stack_b, min, max);
		sorting(stack_a, stack_b, "pa\n");
		min = get_min((*stack_a)->rank, min);
		max = get_max((*stack_a)->rank, max);
	}
}

int	push_swap(t_clist **stack_a, int count)
{
	t_clist	**stack_b;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		return (ft_circ_lstclear(stack_a), free(stack_a), -1);
	*stack_b = NULL;
	if (count > 3)
		sort_push_b(stack_a, stack_b, count);
	if (!check_if_sorted(stack_a))
		mini_sort(stack_a, stack_b);
	if (*stack_b)
		sort_push_a(stack_a, stack_b, count);
	ft_circ_lstclear(stack_a);
	free(stack_a);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	return (1);
}
