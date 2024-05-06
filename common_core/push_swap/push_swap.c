/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:05:34 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 20:24:05 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int count, char **input)
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
			return (ft_free(&new), 0);
		i = count;
		while (--i > 0)
		{
			prev = ft_itoa(ft_atoi(input[i]));
			if (!prev || !ft_strncmp(new, prev, ft_strlen(new) + 1))
				return (ft_free(&new), ft_free(&prev), 0);
			ft_free(&prev);
		}
		ft_free(&new);
	}
	return (1);
}

void	get_ranks(int count, char **params, int *numbers, int *ranks)
{
	int i;
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
	int *numbers;
	int *ranks;

	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	ranks = ft_calloc(sizeof(int), count);
	if (!ranks)
		return (free(numbers), NULL);
	get_ranks(count, params, numbers, ranks);
	stack_a = malloc(sizeof(t_clist *));
	if (!stack_a)
		return (free(numbers), free(ranks), NULL);
	*stack_a = NULL;
	while (--count >= 0)
	{
		current = ft_circ_lstnew(numbers[count], ranks[count]);
		if (!current)
			return (ft_circ_lstclear(stack_a), free(stack_a), NULL);
		ft_circ_lstadd_front(stack_a, current);
	}
	return (free(numbers), free(ranks), stack_a);
}
void	partitioning(t_clist **stack_a, t_clist **stack_b, int count)
{
	t_clist *head;
	int	i;

	head = *stack_a;
	i = 0;
	count += (count % 2 == 0);
	while (i < count / 2)
	{
		head = *stack_a;
		if (head->rank <= count / 2)
		{ 
			sorting(stack_a, stack_b, "pb\n");
			write(1, "pb\n", 3);
			i++;
		}
		else
		{
			sorting(stack_a, stack_b, "ra\n");
			write(1, "ra\n", 3);
		}
	}
}

void	shit_1(t_clist **stack_a, t_clist **stack_b)
{
	int	check1;
	int	check2;

	check1 = (*stack_a)->rank > (*stack_a)->next->rank;
	check2 = (*stack_b)->rank < (*stack_b)->next->rank;
	if (check1 && check2)
	{
		sorting(stack_a, stack_b, "ss\n");
		write(1, "ss\n", 3);
	}
	else if	(check1)
	{
		sorting(stack_a, stack_b, "sa\n");
		write(1, "sa\n", 3);
	}
	else if	(check2)
	{
		sorting(stack_a, stack_b, "sb\n");
		write(1, "sb\n", 3);
	}
}

void	shit_2(t_clist **stack_a, t_clist **stack_b, int count)
{
	int	check1;
	int	check2;

	check1 = (*stack_a)->previous->rank != count &&
		(*stack_a)->previous->rank > (*stack_a)->rank;
	check2 = ((*stack_b)->previous->rank != 1 &&
		(*stack_b)->previous->rank < (*stack_b)->rank);
	if (check1 && check2)
	{
		sorting(stack_a, stack_b, "rrr\n");
		sorting(stack_a, stack_b, "ss\n");
		write(1, "rrr\nss\n", 7);
	}
	else if	(check1)
	{
		sorting(stack_a, stack_b, "rra\n");
		sorting(stack_a, stack_b, "sa\n");
		write(1, "rra\nsa\n", 7);
	}
	else if	(check2)
	{
		sorting(stack_a, stack_b, "rrb\n");
		sorting(stack_a, stack_b, "sb\n");
		write(1, "rrb\nsb\n", 7);
	}
}

void	shit_3(t_clist **stack_a, t_clist **stack_b, int count)
{
	int	check1;
	int	check2;

	check1 = 1;
	check2 = 1;
	(void)count;
	while (check1 || check2)
	{
		check1 = /* (*stack_a)->rank != count / 2 + 1 || */
			(*stack_a)->rank > (*stack_a)->next->rank;
		check2 = /* (*stack_b)->rank != count / 2 ||  */
			(*stack_b)->rank > (*stack_a)->next->rank;
		if (check1 && check2)
		{
			sorting(stack_a, stack_b, "rr\n");
			write(1, "rr\n", 3);
		}
		else if	(check1)
		{
			sorting(stack_a, stack_b, "ra\n");
			write(1, "ra\n", 3);
		}
		else if	(check2)
		{
			sorting(stack_a, stack_b, "rb\n");
			write(1, "rb\n", 3);
		}
	}
}

void	shit_4(t_clist **stack_a, t_clist **stack_b, int count)
{
	if (check_if_sorted(stack_b, -1) && !check_if_sorted(stack_a, 1))
	{
		if ((*stack_a)->rank < (*stack_a)->next->rank &&
		((*stack_a)->previous->rank == count ||
		(*stack_a)->previous->rank < (*stack_a)->rank))
		{
			while ((*stack_a)->rank > (*stack_b)->rank &&
				(*stack_a)->rank < (*stack_a)->next->rank)
			{
				sorting(stack_a, stack_b, "pb\n");
				write(1, "pb\n", 3);
			}
			while (!check_if_sorted(stack_a, 1))
			{
				sorting(stack_a, stack_b, "sa\n");
				sorting(stack_a, stack_b, "pa\n");
				write(1, "sa\npa\n", 6);
			}
		}
	}
}

void	join_stacks(t_clist **stack_a, t_clist **stack_b)
{
	while (*stack_b)
	{
		sorting(stack_a, stack_b, "pa\n");
		write(1, "pa\n", 3);
	}
}

int	push_swap(t_clist **stack_a, int count)
{
	t_clist	**stack_b;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		return (ft_circ_lstclear(stack_a), free(stack_a), -1);
	*stack_b = NULL;
	partitioning(stack_a, stack_b, count);
	while (!check_if_sorted(stack_b, -1) || !check_if_sorted(stack_a, 1))
	{
		shit_1(stack_a, stack_b);
		shit_2(stack_a, stack_b, count);
		shit_3(stack_a, stack_b, count);
		shit_4(stack_a, stack_b, count);
	}
	join_stacks(stack_a, stack_b);
	//print_stack(stack_a);
	ft_circ_lstclear(stack_a);
	free(stack_a);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	return (1);
}
