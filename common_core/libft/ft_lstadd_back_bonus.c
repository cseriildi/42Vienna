/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:03:56 by icseri            #+#    #+#             */
/*   Updated: 2024/04/05 15:57:23 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			curr = *lst;
			while (curr->next)
				curr = curr->next;
			curr->next = new;
		}
	}
}
/* 
int	main(void)
{
	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("1");
	t_list	*node2 = ft_lstnew("2");
	t_list	*node3 = ft_lstnew("3");
	
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);
	t_list	*current = list;
	while (current)
	{
		printf("Content: %s\n", (char *)current->content);
		current = current->next;
	}
	free(node1);
	free(node2);
	free(node3);
} */
