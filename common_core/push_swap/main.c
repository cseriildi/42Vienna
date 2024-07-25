/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:01:22 by icseri            #+#    #+#             */
/*   Updated: 2024/07/25 15:05:40 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	mini_sort(t_var *vars)
{
	if (is_sorted(vars->stack_a) == false)
	{
		if ((*vars->stack_a)->rank > (*vars->stack_a)->next->rank
			&& (*vars->stack_a)->rank > (*vars->stack_a)->previous->rank)
			exec_rule(vars, "ra\n", false);
		if ((*vars->stack_a)->next->rank > (*vars->stack_a)->previous->rank)
			exec_rule(vars, "rra\n", false);
		if ((*vars->stack_a)->rank > (*vars->stack_a)->next->rank)
			exec_rule(vars, "sa\n", false);
	}
}

int	sort(t_var *vars, int count)
{
	if (count <= 3)
		mini_sort(vars);
	else
	{
		vars->stack_b = malloc(sizeof(t_clist *));
		if (!vars->stack_b)
			error(vars);
		*vars->stack_b = NULL;
		sort_push_b(vars, count);
		mini_sort(vars);
		sort_push_a(vars, count);
	}
	if (is_sorted(vars->stack_a) == false)
		return (1);
	return (0);
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
		if (!vars->nums)
			error(vars);
	}
	if (argc == 0 || is_valid_input(argc, vars) == false)
		error(vars);
	vars->stack_a = create_stack(argc, vars);
	if (!vars->stack_a)
		error(vars);
	if (is_sorted(vars->stack_a) == false && sort(vars, argc) == 1)
		error(vars);
	return (free_all(vars), 0);
}
