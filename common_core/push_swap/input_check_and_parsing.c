/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_and_parsing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:07:37 by cseriildii        #+#    #+#             */
/*   Updated: 2024/07/25 15:05:20 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_input(int count, t_var *vars)
{
	char	*new;
	char	*prev;
	int		i;

	while (--count >= 0 && vars->nums)
	{
		new = ft_itoa(ft_atoi(vars->nums[count]));
		if (!new)
			error(vars);
		if (ft_strncmp(vars->nums[count], new, ft_strlen(new) + 1)
			&& ft_strncmp(vars->nums[count], "-0", 3))
			return (free(new), false);
		i = count;
		while (--i >= 0)
		{
			prev = ft_itoa(ft_atoi(vars->nums[i]));
			if (!prev)
				return (free(new), error(vars), false);
			if (!ft_strncmp(new, prev, ft_strlen(new) + 1))
				return (free(new), free(prev), false);
			free(prev);
		}
		free(new);
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
	while (++i < count && params)
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

t_clist	**create_stack(int count, t_var *vars)
{
	t_clist	*current;

	vars->numbers = malloc(sizeof(int) * count);
	if (!vars->numbers)
		error(vars);
	vars->ranks = ft_calloc(sizeof(int), count);
	if (!vars->ranks)
		error(vars);
	get_ranks(count, vars->nums, vars->numbers, vars->ranks);
	vars->stack_a = malloc(sizeof(t_clist *));
	if (!vars->stack_a)
		error(vars);
	*vars->stack_a = NULL;
	while (--count >= 0)
	{
		current = ft_circ_lstnew(vars->numbers[count], vars->ranks[count]);
		if (!current)
			error(vars);
		ft_circ_lstadd_front(vars->stack_a, current);
	}
	return (vars->stack_a);
}
