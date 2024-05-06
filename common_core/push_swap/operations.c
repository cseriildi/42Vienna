/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:06:38 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 19:42:36 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_clist **stack)
{
	t_clist	*head;
	t_clist	*next;
	int		tmp_content;
	int		tmp_rank;

	if (!stack && !*stack)
		return ;
	head = *stack;
	next = head->next;
	tmp_content = head->content;
	tmp_rank = head->rank;
	head->content = next->content;
	head->rank = next->rank;
	next->content = tmp_content;
	next->rank = tmp_rank;
}

void	push(t_clist **stack_src, t_clist **stack_dest)
{
	t_clist	*head;
	t_clist	*head_copy;
	t_clist *next;

	if (!*stack_src)
		return ;
	head = *stack_src;
	next = head->next;
	if (head == next)
		next = NULL;
	head_copy = ft_circ_lstnew(head->content, head->rank);
	if (!head_copy)
	{
		write(2, "I should handle this\n", 22);
		return ;
	}
	ft_circ_lstadd_front(stack_dest, head_copy);
	ft_circ_lstdelone(&head);
	*stack_src = next;
}

void	rotate(t_clist **stack)
{
	if (stack && *stack)
		*stack = (*stack)->next;
}

void	rev_rotate(t_clist **stack)
{
	if (stack && *stack)
		*stack = (*stack)->previous;
}
