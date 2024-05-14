/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_and_parsing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:07:37 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/14 10:36:35 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_input(int count, char **input)
{
	char	*new;
	char	*prev;
	int		i;

	while (--count > 0)
	{
		new = ft_itoa(ft_atoi(input[count]));
		if (!new)
			malloc_failed(NULL, NULL, NULL, NULL);
		if (ft_strncmp(input[count], new, ft_strlen(new) + 1)
			&& ft_strncmp(input[count], "-0", 3))
			return (ft_free(&new), false);
		i = count;
		while (--i > 0)
		{
			prev = ft_itoa(ft_atoi(input[i]));
			if (!prev)
				malloc_failed(NULL, NULL, new, NULL);
			if (!ft_strncmp(new, prev, ft_strlen(new) + 1))
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

void	get_ranks(int count, char **params, int *numbers, int *ranks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count)
		numbers[i] = ft_atoi(params[i]);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (numbers[i] >= numbers[j++])
				ranks[i] += 1;
		}
		i++;
	}
}

t_clist	**create_stack(int count, char **params)
{
	t_clist	**stack_a;
	t_clist	*current;
	int		*numbers;
	int		*ranks;

	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		malloc_failed(NULL, NULL, NULL, NULL);
	ranks = ft_calloc(sizeof(int), count);
	if (!ranks)
		malloc_failed(NULL, NULL, numbers, NULL);
	get_ranks(count, params, numbers, ranks);
	stack_a = malloc(sizeof(t_clist *));
	if (!stack_a)
		malloc_failed(NULL, NULL, numbers, ranks);
	*stack_a = NULL;
	while (--count >= 0)
	{
		current = ft_circ_lstnew(numbers[count], ranks[count]);
		if (!current)
			malloc_failed(stack_a, NULL, numbers, ranks);
		ft_circ_lstadd_front(stack_a, current);
	}
	return (free(numbers), free(ranks), stack_a);
}
