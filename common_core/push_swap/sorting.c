/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:11:45 by icseri            #+#    #+#             */
/*   Updated: 2024/05/08 10:58:22 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_clist **stack)
{
	t_clist	*current;
	t_clist	*head;

	head = *stack;
	current = head;
	while (head != current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sorting(t_clist **stack_a, t_clist **stack_b, char *rule)
{
	if (!ft_strncmp(rule, "sa\n", 3) || !ft_strncmp(rule, "ss\n", 3))
		swap(stack_a);
	if (!ft_strncmp(rule, "sb\n", 3) || !ft_strncmp(rule, "ss\n", 3))
		swap(stack_b);
	if (!ft_strncmp(rule, "pa\n", 3))
		push(stack_b, stack_a);
	if (!ft_strncmp(rule, "pb\n", 3))
		push(stack_a, stack_b);
	if (!ft_strncmp(rule, "ra\n", 3) || !ft_strncmp(rule, "rr\n", 3))
		rotate(stack_a);
	if (!ft_strncmp(rule, "rb\n", 3) || !ft_strncmp(rule, "rr\n", 3))
		rotate(stack_b);
	if (!ft_strncmp(rule, "rra\n", 4) || !ft_strncmp(rule, "rrr\n", 4))
		rev_rotate(stack_a);
	if (!ft_strncmp(rule, "rrb\n", 4) || !ft_strncmp(rule, "rrr\n", 4))
		rev_rotate(stack_b);
	ft_printf("%s", rule);
}

