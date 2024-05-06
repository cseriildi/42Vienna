/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:31 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 18:34:18 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	checker(t_clist	**stack_a)
{
	t_clist	**stack_b;
	char	*instruction;
	int		step_counter;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		return (ft_circ_lstclear(stack_a), free(stack_a), -1);
	*stack_b = NULL;
	instruction = get_next_line(1);
	step_counter = 0;
	while (instruction)
	{
		sorting(stack_a, stack_b, instruction);
		free(instruction);
		step_counter++;
		instruction = get_next_line(1);
	}
	if (check_if_sorted(stack_a, 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_circ_lstclear(stack_a);
	free(stack_a);
	ft_circ_lstclear(stack_b);
	free(stack_b);
	ft_printf("%d\n", step_counter);
	return (step_counter);
}

int	main(int argc, char **argv)
{
	t_clist	**stack_a;

	if (argc > 1)
	{
		if (!check_input(argc, argv))
			return (write(2, "Error\n", 6), -1);
		stack_a = create_stack(argc - 1, argv + 1);
		if (!stack_a)
			return (write(2, "Error\n", 6), -1);
		if (checker(stack_a) == -1)
			return (write(2, "Error\n", 6), -1);
	}
	return (1);
}
