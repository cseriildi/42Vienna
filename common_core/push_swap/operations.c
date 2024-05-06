/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:06:38 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 10:17:04 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_clist **stack)
{
	t_clist	*head;
	t_clist	*next;
	int		tmp_content;
	int		tmp_rank;

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

	head = *stack_src;
	head_copy = ft_circ_lstnew(head->content, head->rank);
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
