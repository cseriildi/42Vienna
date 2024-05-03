/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:05:34 by icseri            #+#    #+#             */
/*   Updated: 2024/05/03 14:13:07 by icseri           ###   ########.fr       */
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

t_clist	**create_stack(int count, int *numbers)
{
	t_clist	**stack_a;
	t_clist	*current;

	stack_a = malloc(sizeof(t_clist *));
	if (!stack_a)
		return (NULL);
	*stack_a = NULL;
	while (--count >= 0)
	{
		current = ft_circ_lstnew(&(numbers[count]));
		if (!current)
			return (ft_circ_lstclear(stack_a), free(stack_a), NULL);
		ft_circ_lstadd_front(stack_a, current);
	}
	return (stack_a);
}

int	push_swap(int count, int *numbers)
{
	t_clist	**stack_a;
	t_clist	*head;
	t_clist	*current;
	int		loop_count;

	stack_a = create_stack(count, numbers);
	if (!stack_a)
		return (0);
	head = *stack_a;
	current = head;
	loop_count = 0;
	while (loop_count++ == 0 || current != head)
	{
		printf("%d\n", *(int *) current->content);
		current = current->next;
	}
	ft_circ_lstclear(stack_a);
	free(stack_a);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	i;

	if (argc > 1)
	{
		if (!check_input(argc, argv))
			return (write(2, "Error\n", 6), -1);
		numbers = malloc(sizeof(int) * (argc - 1));
		if (!numbers)
			return (write(2, "Error\n", 6), -1);
		i = -1;
		while (++i < argc - 1)
			numbers[i] = ft_atoi(argv[i + 1]);
		if (!push_swap(argc - 1, numbers))
			return (free(numbers), write(2, "Error\n", 6), -1);
		free(numbers);
	}
}
