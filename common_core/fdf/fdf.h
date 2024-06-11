/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:47:15 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/11 17:00:58 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h> 
# include <mlx.h>

typedef enum {
    EXIT_SUCCESS,
    EXIT_FAILURE,
	MALLOC_FAIL,
    CANNOT_OPEN_FILE
} ErrorCodes;


typedef struct s_var
{
	char	*filename;
	char	*content;
	char	**str_map;
	int 	**map;
	int		width;
	int		height;
	void 	*mlx;
	void	*window;
}	t_var;


//void	parsing(t_var	*data);



#endif