/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:44:55 by icseri            #+#    #+#             */
/*   Updated: 2024/04/10 19:01:14 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
}
/* 
int	main(int argc, char **argv)
{
	(void)argc;
	ft_putendl_fd(argv[1], atoi(argv[2]));
}
 */