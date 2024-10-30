/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:52:31 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 15:23:55 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	if (lst)
	{
		count++;
		while (lst->next)
		{
			lst = lst->next;
			count++;
		}
	}
	return (count);
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
		current = current->next;
	printf("Size: %d\n", ft_lstsize(list));
	free(node1);
	free(node2);
	free(node3);
}
 */