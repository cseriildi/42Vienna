/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:18:57 by icseri            #+#    #+#             */
/*   Updated: 2024/05/20 11:06:08 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	number_count(char const *str, char c)
{
	int		counter;
	char	prev;

	prev = c;
	counter = 0;
	while (*str)
	{
		if (*str != c && prev == c)
			counter++;
		prev = *str;
		str++;
	}
	return (counter);
}

char	**stack_to_heap(char **stack_array, int size)
{
	int		i;
	char	**heap_array;

	heap_array = malloc((size + 1) * sizeof(char *));
	if (!heap_array)
		malloc_failed(NULL, NULL, NULL, NULL);
	i = 0;
	while (i < size)
	{
		heap_array[i] = ft_strdup(stack_array[i]);
		if (!heap_array[i])
			malloc_failed(NULL, heap_array, NULL, NULL);
		i++;
	}
	heap_array[size] = NULL;
	return (heap_array);
}

/* 
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
 */