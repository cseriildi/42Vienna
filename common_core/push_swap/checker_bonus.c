/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:31 by icseri            #+#    #+#             */
/*   Updated: 2024/07/25 15:06:09 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_var	*init(t_var *vars)
{
	vars = malloc(sizeof(t_var));
	if (!vars)
		error(vars);
	vars->stack_a = NULL;
	vars->stack_b = NULL;
	vars->nums = NULL;
	vars->numbers = NULL;
	vars->ranks = NULL;
	return (vars);
}

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

void	checker(t_var *vars)
{
	char	*instruction;

	vars->stack_b = malloc(sizeof(t_clist *));
	if (!vars->stack_b)
		error(vars);
	*vars->stack_b = NULL;
	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		if (is_valid_rule(instruction) == false)
		{
			free(instruction);
			get_next_line(-1);
			error(vars);
		}
		exec_rule(vars, instruction, true);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(vars->stack_a) == true && *vars->stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_var	*vars;

	if (--argc <= 0)
		return (0);
	vars = NULL;
	vars = init(vars);
	if (argc > 1)
		stack_to_heap(++argv, argc, vars);
	if (argc == 1)
	{
		argc = number_count(argv[1], ' ');
		vars->nums = ft_split(argv[1], ' ');
	}
	if (argc == 0 || is_valid_input(argc, vars) == false)
		return (error(vars), 1);
	vars->stack_a = create_stack(argc, vars);
	if (!vars->stack_a)
		error(vars);
	checker(vars);
	return (free_all(vars), 0);
}
