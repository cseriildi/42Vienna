/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:31 by icseri            #+#    #+#             */
/*   Updated: 2024/05/03 16:56:37 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	checker(int count, int *numbers, char **instructions)
{
	t_clist	**stack_a;
	t_clist	**stack_b;
	t_clist	*head;
	t_clist	*current;
	int		loop_count;

	stack_a = create_stack(count, numbers);
	if (!stack_a)
		return (0);
	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		return (ft_circ_lstclear(stack_a), free(stack_a), 0);
	*stack_b = NULL;
	while (*instructions)
		sorting(stack_a, stack_b, *instructions++);
	if (check_if_sorted(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_circ_lstclear(stack_a);
	free(stack_a);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	return (1);
}

int	bonus_main(int argc, char **argv)
{
	int		*numbers;
	int		i;
	char	**instructions;

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
		if (!checker(argc - 1, numbers))
			return (free(numbers), write(2, "Error\n", 6), -1);
		free(numbers);
	}
}
