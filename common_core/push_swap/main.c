/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:01:22 by icseri            #+#    #+#             */
/*   Updated: 2024/05/12 11:32:12 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_clist **a)
{
	if (is_sorted(a) == false)
	{
		if ((*a)->rank > (*a)->next->rank && (*a)->rank > (*a)->previous->rank)
			exec_rule(a, NULL, "ra\n", false);
		if ((*a)->next->rank > (*a)->previous->rank)
			exec_rule(a, NULL, "rra\n", false);
		if ((*a)->rank > (*a)->next->rank)
			exec_rule(a, NULL, "sa\n", false);
	}
}

int	sort(t_clist **a, int count)
{
	t_clist	**b;

	if (count <= 3)
		mini_sort(a);
	else
	{
		b = malloc(sizeof(t_clist *));
		if (!b)
			malloc_failed(a, NULL, NULL, NULL);
		*b = NULL;
		sort_push_b(a, b, count);
		mini_sort(a);
		sort_push_a(a, b, count);
		ft_circ_lstclear(b);
		free(b);
	}
	if (is_sorted(a) == false)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_clist	**stack_a;

	if (argc > 1)
	{
		if (is_valid_input(argc, argv) == false)
			return (write(2, "Error\n", 6), 1);
		stack_a = create_stack(argc - 1, argv + 1);
		if (!stack_a)
			malloc_failed(NULL, NULL, NULL, NULL);
		if (is_sorted(stack_a) == false)
		{
			if (sort(stack_a, argc - 1) == 1)
			{
				ft_circ_lstclear(stack_a);
				free(stack_a);
				write(2, "Error\n", 6);
				return (1);
			}
		}
		ft_circ_lstclear(stack_a);
		free(stack_a);
	}
	return (0);
}
