/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:11:45 by icseri            #+#    #+#             */
/*   Updated: 2024/05/03 16:55:29 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_clist **stack_a, t_clist **stack_b, char *rule)
{
	if (!ft_strncmp(rule, "sa", 2) || !ft_strncmp(rule, "ss", 2))
		swap(stack_a);
	else if (!ft_strncmp(rule, "sb", 2) || !ft_strncmp(rule, "ss", 2))
		swap(stack_b);
	else if (!ft_strncmp(rule, "pa", 2))
		push(stack_a, stack_b);
	else if (!ft_strncmp(rule, "pb", 2))
		push(stack_b, stack_a);
	else if (!ft_strncmp(rule, "ra", 2) || !ft_strncmp(rule, "rr", 2))
		rotate(stack_a);
	else if (!ft_strncmp(rule, "rb", 2) || !ft_strncmp(rule, "rr", 2))
		rotate(stack_b);
	else if (!ft_strncmp(rule, "rra", 3) || !ft_strncmp(rule, "rrr", 3))
		rev_rotate(stack_a);
	else if (!ft_strncmp(rule, "rrb", 3) || !ft_strncmp(rule, "rrr", 3))
		rev_rotate(stack_b);
	else
		write(2, "I should handle this\n", 22);
}

int	check_if_sorted(t_clist **stack_a, t_clist **stack_b)
{
	t_clist	*current;
	t_clist	*head;

	head = *stack_a;
	current = head->next;
	while (head != current)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	ft_circ_lstclear(stack_a);
	free(stack_a);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	return (1);
}
