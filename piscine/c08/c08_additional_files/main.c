/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:28:46 by icseri            #+#    #+#             */
/*   Updated: 2024/02/29 16:28:57 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_show_tab(struct s_stock_str *par);

int	main(int argc, char **argv)
{
	struct s_stock_str	*result = ft_strs_to_tab(argc, argv);
	int	i;

	if (result == NULL)
		printf("Memory allocation failed\n");
	ft_show_tab(result);
	i = 0;
	while (result[i].str != NULL)
	{
		free(result[i].copy);
		i++;
	}
	free(result);
}
