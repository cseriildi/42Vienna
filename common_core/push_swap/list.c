/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:48:54 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 11:50:39 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*ft_circ_lstnew(int content, int rank)
{
	t_clist	*new_node;

	new_node = malloc(sizeof(t_clist));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->rank = rank;
	new_node->price = 0;
	new_node->next = new_node;
	new_node->previous = new_node;
	return (new_node);
}

void	ft_circ_lstadd_front(t_clist **lst, t_clist *new)
{
	if (lst && new)
	{
		if (*lst)
		{
			new->next = *lst;
			new->previous = (*lst)->previous;
			(*lst)->previous->next = new;
			(*lst)->previous = new;
		}
		*lst = new;
	}
}

void	ft_circ_lstdelone(t_clist **lst)
{
	if (lst && *lst)
	{
		(*lst)->previous->next = (*lst)->next;
		(*lst)->next->previous = (*lst)->previous;
		free(*lst);
		*lst = NULL;
	}
}

void	ft_circ_lstclear(t_clist **lst)
{
	t_clist	*head;
	t_clist	*current;
	t_clist	*next;

	if (lst && *lst)
	{
		head = *lst;
		current = head->next;
		while (current != head)
		{
			next = current->next;
			ft_circ_lstdelone(&current);
			current = next;
		}
		ft_circ_lstdelone(lst);
	}
	*lst = NULL;
}

int	ft_circ_lstsize(t_clist **lst)
{
	t_clist	*head;
	t_clist	*current;
	int		size;

	if (lst && *lst)
	{
		size = 1;
		head = *lst;
		current = head->next;
		while (current != head)
		{
			current = current->next;
			size++;
		}
	}
	return (size);
}
