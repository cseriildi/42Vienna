/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:34:07 by icseri            #+#    #+#             */
/*   Updated: 2024/04/08 15:36:41 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i] && f)
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
void	test_function(unsigned int i, char *str)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
}

int	main(int argc, char **argv)
{
	(void)argc;
	ft_striteri(argv[1], test_function);
	ft_putstr_fd(argv[1], 1);
}
 */