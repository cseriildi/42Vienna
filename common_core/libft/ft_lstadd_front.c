/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:00:29 by icseri            #+#    #+#             */
/*   Updated: 2024/04/05 15:46:46 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/* int	main(void)
{
	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("1");
	t_list	*node2 = ft_lstnew("2");
	t_list	*node3 = ft_lstnew("3");

	ft_lstadd_front(&list, node3);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node1);
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
