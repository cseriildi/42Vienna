/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:17 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 10:51:28 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
/* 
# include <fcntl.h>
# include <stdio.h>
*/

# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*line_search(char *s);
int		is_nl(char *read_chars);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

#endif
