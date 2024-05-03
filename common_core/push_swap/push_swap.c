/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:05:34 by icseri            #+#    #+#             */
/*   Updated: 2024/05/03 10:11:38 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int count, char **input)
{
	char	*orig_str;
	char	*new_str;
	char	*prev_str;
	int		i;

	while (--count > 0)
	{
		orig_str = input[count];
		new_str = ft_itoa(ft_atoi(orig_str));
		if (new_str == NULL)
			return (0);
		if (ft_strncmp(orig_str, new_str, ft_strlen(new_str))
			&& ft_strncmp(orig_str, "-0", 2))
			return (free(new_str), 0);
		i = count;
		while (--i > 0)
		{
			prev_str = ft_itoa(ft_atoi(input[i]));
			if (!prev_str)
				return (free(new_str), 0);
			if (!ft_strncmp(new_str, prev_str, ft_strlen(new_str) +1))
				return (free(new_str), free(prev_str), 0);
			free(prev_str);
		}
		free(new_str);
	}
	return (1);
}

t_clist	**create_stack(int count, int *numbers)
{
	t_clist	**stack_a;
	t_clist	*current;
	

	stack_a = malloc(sizeof(t_clist *));
	if (stack_a == NULL)
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
    t_clist **stack_a;
    t_clist *head;
    t_clist *current;
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