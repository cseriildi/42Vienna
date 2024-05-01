/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:05:34 by icseri            #+#    #+#             */
/*   Updated: 2024/05/01 17:04:46 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_list **stack) 
{

    t_list *current = *stack;
    t_list *next;

	while (current) 
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}

int	check_input(int count, char **input)
{
	char *orig_str;
	int	num;
	char *new_str;

	while (--count > 0)
	{
		orig_str = input[count];
		num = ft_atoi(orig_str);
		new_str = ft_itoa(num);
		if (new_str == NULL)
			return (0);
		if (ft_strncmp(orig_str, new_str, ft_strlen(new_str))
			&& ft_strncmp(orig_str, "-0", 3))
			return (free(new_str), 0);
		free(new_str);
	}
	return (1);
}

t_list	**create_stack(int count, char **input)
{
	t_list	**stack_a;
	t_list	*current;

	stack_a = malloc(sizeof(t_list *));
	if (stack_a == NULL)
		return (NULL);
	*stack_a = NULL;
	while (--count > 0)
	{
		current = ft_lstnew(input[count]);
		if (!current)
			return (free_stack(stack_a), NULL);
		ft_lstadd_front(stack_a, current);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	*lst;

	if (argc > 1)
	{
		if (!check_input(argc, argv))
			return (write(2, "Error\n", 6), -1);
		stack_a = create_stack(argc, argv);
		if (!stack_a)
			return (write(2, "Error\n", 6), -1);
		lst = *stack_a;
		while (lst)
		{
			printf("%s\n", (char *) lst->content);
			lst = lst->next;
		}
		//free_stack(stack_a); 
	}
}