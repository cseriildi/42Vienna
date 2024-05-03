/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:06:38 by icseri            #+#    #+#             */
/*   Updated: 2024/05/03 11:43:13 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_clist **stack)
{
	t_clist	*head;
	t_clist	*next;
	int	*tmp;

	head = *stack;
	next = head->next;
	tmp = head->content;
	head->content = next->content;
	next->content = tmp;
}

void	push(t_clist **stack_src, t_clist **stack_dest)
{
	t_clist	*head;
	t_clist	*head_copy;

	head = *stack_src;
	head_copy = ft_circ_lstnew(head->content);
	if (!head_copy)
	{
		write(2, "I should handle this\n", 22);
		return ;
	}
	ft_circ_lstadd_front(stack_dest, head_copy);
	ft_circ_lstdelone(&head);
}

void	rotate(t_clist **head)
{
	if (*head != NULL)
		*head = (*head)->next;
}


void	rev_rotate(t_clist **head)
{
	if (*head != NULL)
		*head = (*head)->previous;
}