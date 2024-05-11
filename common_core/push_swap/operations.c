/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:06:38 by icseri            #+#    #+#             */
/*   Updated: 2024/05/11 15:18:24 by cseriildii       ###   ########.fr       */
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
	t_clist	*next;

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

void	exec_rule(t_clist **a, t_clist **b, char *rule, bool is_bonus)
{
	if (!ft_strncmp(rule, "sa\n", 3) || !ft_strncmp(rule, "ss\n", 3))
		swap(a);
	if (!ft_strncmp(rule, "sb\n", 3) || !ft_strncmp(rule, "ss\n", 3))
		swap(b);
	if (!ft_strncmp(rule, "pa\n", 3))
		push(b, a);
	if (!ft_strncmp(rule, "pb\n", 3))
		push(a, b);
	if (!ft_strncmp(rule, "ra\n", 3) || !ft_strncmp(rule, "rr\n", 3))
		rotate(a);
	if (!ft_strncmp(rule, "rb\n", 3) || !ft_strncmp(rule, "rr\n", 3))
		rotate(b);
	if (!ft_strncmp(rule, "rra\n", 4) || !ft_strncmp(rule, "rrr\n", 4))
		rev_rotate(a);
	if (!ft_strncmp(rule, "rrb\n", 4) || !ft_strncmp(rule, "rrr\n", 4))
		rev_rotate(b);
	if (!is_bonus)
		ft_printf("%s", rule);
}
