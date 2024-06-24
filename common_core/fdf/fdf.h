/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:47:15 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/24 12:18:02 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h> 
# include <mlx.h>
# include <math.h>

# define ESC 65307
# define CLICK_ON_X 17

# define WIDTH 1200
# define HEIGHT 900
# define ANGLE -30
# define BASE_COLOR 16777215

# define PI 3.14159265358979323846

typedef enum s_err
{
	MALLOC_FAIL = 2,
	WRONG_INPUT,
	CANNOT_OPEN_FILE
}	t_err;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		en;
}	t_image;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
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
	double	angle;
	double	scale;
	void	*display;
	void	*window;
	t_image	img;
	double	x_offset;
	double	y_offset;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	int		delta_x;
	int		delta_y;
	int		sign_x;
	int		sign_y;
	double	error;
	double	error2;
}	t_var;

//utils
void	safe_exit(t_var *data, int error_code);
int		ft_max(int count, ...);
void	array_free(t_point ***arr);
void	char_array_free(char ***arr);

//events
int		handle_esc(int key, t_var *data);
int		handle_close(t_var *data);

//parsing
void	create_map(t_var *data);

//iso
void	create_2d(t_var *data);

//atoi base
int		ft_atoi_hex(char *str);

//fdf
void	init_data(t_var *data);

//drawing
void	draw(t_var *data);

#endif