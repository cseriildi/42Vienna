/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:01:22 by icseri            #+#    #+#             */
/*   Updated: 2024/05/11 15:56:13 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_clist	**stack_a;

	if (argc > 1)
	{
		if (is_valid_input(argc, argv) == false)
			return (write(2, "Error\n", 6), 1);
		stack_a = create_stack(argc - 1, argv + 1);
		if (!stack_a)
			return (write(2, "Error\n", 6), 1);
		if (is_sorted(stack_a) == false)
		{
			if (sort(stack_a, argc - 1) == -1)
			{
				ft_circ_lstclear(stack_a);
				free(stack_a);
				write(2, "Error\n", 6);
				return (1);
			}
		}
		ft_circ_lstclear(stack_a);
		free(stack_a);
		return (0);
	}
	return (1);
}
