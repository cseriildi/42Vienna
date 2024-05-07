/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:50:39 by icseri            #+#    #+#             */
/*   Updated: 2024/05/07 11:51:57 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partitioning(t_clist **stack_a, t_clist **stack_b, int count)
{
	t_clist *head;
	int	i;

	head = *stack_a;
	i = 0;
	//count += (count % 2 == 0);
	while (i < count / 2)
	{
		head = *stack_a;
		if (head->rank <= count / 2)
		{ 
			sorting(stack_a, stack_b, "pb\n");
			write(1, "pb\n", 3);
			i++;
		}
		else
		{
			sorting(stack_a, stack_b, "ra\n");
			write(1, "ra\n", 3);
		}
	}
}

bool	check_swap_a(t_clist **stack_a)
{
	return ((*stack_a)->rank > (*stack_a)->next->rank);
}

bool	check_swap_b(t_clist **stack_b)
{
	return ((*stack_b)->rank < (*stack_b)->next->rank);
}

void	shit_1(t_clist **stack_a, t_clist **stack_b)
{
	if (check_swap_a(stack_a) && check_swap_b(stack_b))
	{
		sorting(stack_a, stack_b, "ss\n");
		write(1, "ss\n", 3);
	}
	else if	(check_swap_a(stack_a))
	{
		sorting(stack_a, stack_b, "sa\n");
		write(1, "sa\n", 3);
	}
	else if	(check_swap_b(stack_b))
	{
		sorting(stack_a, stack_b, "sb\n");
		write(1, "sb\n", 3);
	}
}

bool	check_rev_swap_a(t_clist **stack_a, int count)
{
	return ((*stack_a)->previous->rank > (*stack_a)->rank &&
		(*stack_a)->previous->rank != count);
}

bool	check_rev_swap_b(t_clist **stack_b)
{
	return ((*stack_b)->previous->rank < (*stack_b)->rank &&
		(*stack_b)->previous->rank != 1);
}

void	shit_2(t_clist **stack_a, t_clist **stack_b, int count)
{
	if (check_rev_swap_a(stack_a, count) && check_rev_swap_b(stack_b))
	{
		sorting(stack_a, stack_b, "rrr\n");
		sorting(stack_a, stack_b, "ss\n");
		write(1, "rrr\nss\n", 7);
	}
	else if	(check_rev_swap_a(stack_a, count))
	{
		sorting(stack_a, stack_b, "rra\n");
		sorting(stack_a, stack_b, "sa\n");
		write(1, "rra\nsa\n", 7);
	}
	else if	(check_rev_swap_b(stack_b))
	{
		sorting(stack_a, stack_b, "rrb\n");
		sorting(stack_a, stack_b, "sb\n");
		write(1, "rrb\nsb\n", 7);
	}
}


bool	check_rotate_a(t_clist **stack_a,  int count)
{
	return (!check_if_sorted(stack_a, 1) && !check_swap_a(stack_a)
		&& !check_rev_swap_a(stack_a, count));
}

bool	check_rotate_b(t_clist **stack_b)
{
	return (!check_if_sorted(stack_b, -1) && !check_swap_b(stack_b)
		&& !check_rev_swap_b(stack_b));
}

void	shit_3(t_clist **stack_a, t_clist **stack_b, int count)
{
	if (check_rotate_a(stack_a, count) && check_rotate_b(stack_b))
	{
		sorting(stack_a, stack_b, "rr\n");
		write(1, "rr\n", 3);
	}
	else if	(check_rotate_a(stack_a, count))
	{
		sorting(stack_a, stack_b, "ra\n");
		write(1, "ra\n", 3);
	}
	else if	(check_rotate_b(stack_b))
	{
		sorting(stack_a, stack_b, "rb\n");
		write(1, "rb\n", 3);
	}
}

void	shit_4(t_clist **stack_a, t_clist **stack_b, int count)
{
	if (check_if_sorted(stack_b, -1) && !check_if_sorted(stack_a, 1))
	{
		if ((*stack_a)->rank < (*stack_a)->next->rank &&
		((*stack_a)->previous->rank == count ||
		(*stack_a)->previous->rank < (*stack_a)->rank))
		{
			while ((*stack_a)->rank > (*stack_b)->rank &&
				(*stack_a)->rank < (*stack_a)->next->rank)
			{
				sorting(stack_a, stack_b, "pb\n");
				write(1, "pb\n", 3);
			}
			while (!check_if_sorted(stack_a, 1))
			{
				sorting(stack_a, stack_b, "sa\n");
				sorting(stack_a, stack_b, "pa\n");
				write(1, "sa\npa\n", 6);
			}
		}
	}
}

void	join_stacks(t_clist **stack_a, t_clist **stack_b)
{
	while (*stack_b)
	{
		sorting(stack_a, stack_b, "pa\n");
		write(1, "pa\n", 3);
	}
}

int	push_swap_o(t_clist **stack_a, int count)
{
	t_clist	**stack_b;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		return (ft_circ_lstclear(stack_a), free(stack_a), -1);
	*stack_b = NULL;
	partitioning(stack_a, stack_b, count);
	while (!check_if_sorted(stack_b, -1) || !check_if_sorted(stack_a, 1))
	{
		shit_1(stack_a, stack_b);
		shit_2(stack_a, stack_b, count);
		shit_3(stack_a, stack_b, count);
		//shit_4(stack_a, stack_b, count);
	}
	join_stacks(stack_a, stack_b);
	//print_stack(stack_a);
	ft_circ_lstclear(stack_a);
	free(stack_a);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	return (1);
}
