/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:17 by icseri            #+#    #+#             */
/*   Updated: 2024/04/22 16:49:36 by icseri           ###   ########.fr       */
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

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*line_search(char *s);
int		is_nl(char *read_chars);
void	ft_free(char **p);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

#endif
