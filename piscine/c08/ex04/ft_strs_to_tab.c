/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:33:15 by icseri            #+#    #+#             */
/*   Updated: 2024/02/27 16:33:17 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	dest = malloc(sizeof(src));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	struct s_stock_str	arr;
	
	i = 0;
	while (i < ac)
	{
		arr.size[i] = ft_strlen(av[i]);
		arr.str[i] = ft_strcpy(arr.str[i], av[i]);
		arr.copy[i] = ft_strcpy(arr.copy[i], arr.str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	ft_strs_to_tab(argc, argv);
	
}
