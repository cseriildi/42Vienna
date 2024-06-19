/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:47:15 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/19 15:56:01 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h> 
//# include "mlx/mlx.h"
# include <mlx.h>
# include <math.h>

# define ESC 65307
# define CLICK_ON_X 17

# define WIDTH 1200
# define HEIGHT 900
# define ANGLE 30
# define BASE_COLOR 0xFFFFFF

# define PI 3.14159265358979323846

typedef enum
{
	MALLOC_FAIL = 2,
	WRONG_INPUT,
	CANNOT_OPEN_FILE
}	ErrorCodes;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int color;
}	t_point;


typedef struct s_var
{
	char	*filename;
	char	*content;
	char	**str_map;
	char	**line;
	t_point	**map;
	t_point	**map_2d;
	int		width;
	int		height;
	int		angle;
	float	scale;
	void	*display;
	void	*window;
	t_image	image;
	int		x_offset;
	int		y_offset;
	int		x_min;
	int		y_min;
	int		x_max;
	int		y_max;
}	t_var;

void	safe_exit(t_var *data, int error_code);
int	ft_max(int count, ...);

//events
int	handle_esc(int key, t_var *data);
int	handle_close(t_var *data);

void	array_free(t_point ***arr);
void	char_array_free(char ***arr);

void	create_map(t_var *data);

//iso
void	create_2d(t_var *data);

//atoi base
int	ft_atoi_base(const char *str, char *base);

void	draw(t_var *data);

#endif