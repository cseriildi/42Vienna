/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:18:57 by icseri            #+#    #+#             */
/*   Updated: 2024/05/14 11:07:38 by icseri           ###   ########.fr       */
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

void	malloc_failed(t_clist **stack_a, t_clist **stack_b, void *p1, void *p2)
{
	if (stack_a)
	{
		ft_circ_lstclear(stack_a);
		free(stack_a);
	}
	if (stack_b)
	{
		ft_circ_lstclear(stack_b);
		free(stack_b);
	}
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	write(2, "Error\n", 6);
	exit(1);
}

int	min(int count, ...)
{
	va_list	numbers;
	int		min;
	int		num;

	va_start(numbers, count);
	min = va_arg(numbers, int);
	while (--count > 0)
	{
		num = va_arg(numbers, int);
		if (num < min)
			min = num;
	}
	va_end(numbers);
	return (min);
}

int	max(int count, ...)
{
	va_list	numbers;
	int		max;
	int		num;

	va_start(numbers, count);
	max = va_arg(numbers, int);
	while (--count > 0)
	{
		num = va_arg(numbers, int);
		if (num > max)
			max = num;
	}
	va_end(numbers);
	return (max);
}

void	print_stack(t_clist **stack)
{
	t_clist	*head;
	t_clist	*current;
	int		loopcount;

	head = *stack;
	current = head;
	loopcount = 0;
	while (loopcount++ == 0 || current != head)
	{
		ft_printf("%d\n", current->rank);
		current = current->next;
	}
}
