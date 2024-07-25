/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:18:57 by icseri            #+#    #+#             */
/*   Updated: 2024/07/18 18:29:10 by icseri           ###   ########.fr       */
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

void	stack_to_heap(char **stack_array, int size, t_var *vars)
{
	int		i;

	vars->nums = malloc((size + 1) * sizeof(char *));
	if (!vars->nums)
		error(vars);
	i = 0;
	while (i < size)
	{
		vars->nums[i] = ft_strdup(stack_array[i]);
		if (!vars->nums[i])
			error(vars);
		i++;
	}
	vars->nums[size] = NULL;
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