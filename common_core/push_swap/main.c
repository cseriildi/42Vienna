/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:01:22 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 11:54:19 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (check_if_sorted(stack_a, 0))
			return (ft_circ_lstclear(stack_a), free(stack_a), 0);
		if (push_swap(stack_a) == -1)
			return (write(2, "Error\n", 6), -1);
	}
}
