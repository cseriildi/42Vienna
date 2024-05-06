/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:18:57 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 11:42:48 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

void	print_stack(t_clist **stack)
{
	t_clist	*head;
	t_clist	*current;
	int	loopcount;

	head = *stack;
	current = head;
	loopcount = 0;
	while (loopcount++ == 0 || current != head)
	{
		ft_printf("%d\n", current->rank);
		current = current->next;
	}
}