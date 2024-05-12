/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:31 by icseri            #+#    #+#             */
/*   Updated: 2024/05/12 11:14:52 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker(t_clist	**stack_a)
{
	t_clist	**stack_b;
	char	*instruction;
	int		step_counter;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		malloc_failed(stack_a, NULL, NULL, NULL);
	*stack_b = NULL;
	step_counter = 0;
	instruction = get_next_line(1);
	while (instruction)
	{
		exec_rule(stack_a, stack_b, instruction, true);
		free(instruction);
		step_counter++;
		instruction = get_next_line(1);
	}
	if (is_sorted(stack_a) == true && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_circ_lstclear(stack_b);
	free(stack_b);
	free(instruction);
}

int	main(int argc, char **argv)
{
	t_clist	**stack_a;

	if (argc > 1)
	{
		if (is_valid_input(argc, argv) == false)
			return (write(2, "Error\n", 6), 1);
		stack_a = create_stack(argc - 1, argv + 1);
		if (!stack_a)
			malloc_failed(NULL, NULL, NULL, NULL);
		checker(stack_a);
		ft_circ_lstclear(stack_a);
		free(stack_a);
	}
	return (0);
}
