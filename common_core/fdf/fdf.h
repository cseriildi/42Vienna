/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:47:15 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/09 10:50:26 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h> 

/* typedef enum {
    EXIT_SUCCESS,
    EXIT_FAILURE,
    ERROR_MISUSE,
    CANNOT_OPEN_FILE,
    MALLOC_FAIL
} ErrorCodes; */


typedef struct s_var
{
	char	*filename;
	char	*content;
	char	**str_map;
	int 	**map;
	int		width;
	int		height;
}	t_var;


void	parsing(t_var	*data);



#endif