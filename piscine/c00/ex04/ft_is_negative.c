/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:29:57 by icseri            #+#    #+#             */
/*   Updated: 2024/02/15 11:53:45 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	ft_is_negative(int x)
{
	char	n_or_p;

	if (x < 0)
	{
		n_or_p = 'N';
	}
	else
	{
		n_or_p = 'P';
	}
	write(1, &n_or_p, 1);
}
/*
int	main(int argc, char **argv)
{
	int	i;
	
	i = 1;
	while (i < argc)
	{
		ft_is_negative(atoi(argv[i]));
		i++;
	}
}*/
