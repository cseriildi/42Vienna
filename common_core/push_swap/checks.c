/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:07:37 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/11 15:35:14 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_input(int count, char **input)
{
	char	*orig;
	char	*new;
	char	*prev;
	int		i;

	while (--count > 0)
	{
		orig = input[count];
		new = ft_itoa(ft_atoi(orig));
		if (!new || (ft_strncmp(orig, new, ft_strlen(new) + 1)
				&& ft_strncmp(orig, "-0", 3)))
			return (ft_free(&new), false);
		i = count;
		while (--i > 0)
		{
			prev = ft_itoa(ft_atoi(input[i]));
			if (!prev || !ft_strncmp(new, prev, ft_strlen(new) + 1))
				return (ft_free(&new), ft_free(&prev), false);
			ft_free(&prev);
		}
		ft_free(&new);
	}
	return (true);
}

bool	is_sorted(t_clist **stack)
{
	t_clist	*current;
	t_clist	*head;

	head = *stack;
	current = head;
	while (head != current->next)
	{
		if (current->rank > current->next->rank)
			return (false);
		current = current->next;
	}
	return (true);
}
