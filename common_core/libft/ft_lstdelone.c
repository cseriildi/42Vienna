/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:40:04 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 12:59:38 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
/* void	delete_content(void *content)
{
	free(content);
} */
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
	
	ft_lstdelone(node2, delete_content);

	while (current)
	{
		printf("Content: %s\n", (char *)current->content);
		current = current->next;
	}
} */

/* int main() {
    t_list *list = NULL;
    t_list *node1 = ft_lstnew("1");
    t_list *node2 = ft_lstnew("2");
    t_list *node3 = ft_lstnew("3");

    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);

    t_list *current = list;
	ft_lstdelone(current, &delete_content);
	while (current)
	{
		printf("Content: %s\n", (char *)current->content);
		current = current->next;
	}
} */
