/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:05:34 by icseri            #+#    #+#             */
/*   Updated: 2024/07/18 18:30:09 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_index(t_clist **stack, int count)
{
	t_clist	*current;
	int		loopcount;

	loopcount = 0;
	current = *stack;
	while (loopcount < count)
	{
		current->r_index = loopcount++;
		current = current->next;
		current->rr_index = count - loopcount;
	}
}

void	set_price(t_clist *node_a, t_clist *node_b)
{
	int	rr;
	int	rrr;
	int	ra_rrb;
	int	rra_rb;
	int	price;

	rr = max(2, node_a->r_index, node_b->r_index);
	rrr = max(2, node_a->rr_index, node_b->rr_index);
	ra_rrb = node_a->r_index + node_b->rr_index;
	rra_rb = node_a->rr_index + node_b->r_index;
	price = min(4, rr, rrr, ra_rrb, rra_rb);
	node_a->price = price;
	node_b->price = price;
}

void	rotate_to_push(t_var *vars, t_clist *n_a, t_clist *n_b)
{
	if (max(2, n_a->r_index, n_b->r_index) == n_a->price)
	{
		repeat_rule(vars, min(2, n_a->r_index, n_b->r_index), "rr\n");
		repeat_rule(vars, n_a->r_index - n_b->r_index, "ra\n");
		repeat_rule(vars, n_b->r_index - n_a->r_index, "rb\n");
	}
	else if (max(2, n_a->rr_index, n_b->rr_index) == n_a->price)
	{
		repeat_rule(vars, min(2, n_a->rr_index, n_b->rr_index), "rrr\n");
		repeat_rule(vars, n_a->rr_index - n_b->rr_index, "rra\n");
		repeat_rule(vars, n_b->rr_index - n_a->rr_index, "rrb\n");
	}
	else if (n_a->r_index + n_b->rr_index == n_a->price)
	{
		repeat_rule(vars, n_a->r_index, "ra\n");
		repeat_rule(vars, n_b->rr_index, "rrb\n");
	}
	else
	{
		repeat_rule(vars, n_a->rr_index, "rra\n");
		repeat_rule(vars, n_b->r_index, "rb\n");
	}
}
