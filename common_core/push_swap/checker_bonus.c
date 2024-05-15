/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:31 by icseri            #+#    #+#             */
/*   Updated: 2024/05/15 12:41:05 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	is_valid_rule(char *rule)
{
	if (!ft_strncmp(rule, "sa\n", 3) || !ft_strncmp(rule, "ss\n", 3)
		|| !ft_strncmp(rule, "sb\n", 3) || !ft_strncmp(rule, "ss\n", 3)
		|| !ft_strncmp(rule, "pa\n", 3) || !ft_strncmp(rule, "pb\n", 3)
		|| !ft_strncmp(rule, "ra\n", 3) || !ft_strncmp(rule, "rr\n", 3)
		|| !ft_strncmp(rule, "rb\n", 3) || !ft_strncmp(rule, "rr\n", 3)
		|| !ft_strncmp(rule, "rra\n", 4) || !ft_strncmp(rule, "rrr\n", 4)
		|| !ft_strncmp(rule, "rrb\n", 4) || !ft_strncmp(rule, "rrr\n", 4))
		return (true);
	return (false);
}

void	checker(t_clist	**stack_a)
{
	t_clist	**stack_b;
	char	*instruction;

	stack_b = malloc(sizeof(t_clist *));
	if (!stack_b)
		malloc_failed(stack_a, NULL, NULL, NULL);
	*stack_b = NULL;
	instruction = get_next_line(0);
	while (instruction)
	{
		if (is_valid_rule(instruction) == false)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		exec_rule(stack_a, stack_b, instruction, true);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (is_sorted(stack_a) == true && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_circ_lstclear(stack_b);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	t_clist	**stack_a;
	char	**numbers;

	if (--argc > 0)
	{
		numbers = ++argv;
		if (argc == 1)
		{
			numbers = ft_split(argv[0], ' ');
			argc = number_count(argv[0], ' ');
		}
		if (is_valid_input(argc, numbers) == false)
			return (write(2, "Error\n", 6), 1);
		stack_a = create_stack(argc, numbers);
		if (!stack_a)
			malloc_failed(NULL, NULL, NULL, NULL);
		checker(stack_a);
		ft_circ_lstclear(stack_a);
		free(stack_a);
	}
	return (0);
}
