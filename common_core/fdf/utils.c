/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:21:07 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/18 13:38:24 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;

	if (new_size == 0)
    {
        if (ptr != NULL)
			free(ptr);
        return NULL;
    }
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;
    if (ptr != NULL)
    {
        if (old_size < new_size)
			ft_memcpy(new_ptr, ptr, old_size);
		else
			ft_memcpy(new_ptr, ptr, new_size);
        free(ptr); 
    }
    return new_ptr;
}

void	array_free(t_point ***arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while ((*arr)[i])
		{
			free((*arr)[i]);
			i++;
		}
		free(*arr);
		*arr = NULL;
	}
}

void	char_array_free(char ***arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while ((*arr)[i])
		{
			free((*arr)[i]);
			i++;
		}
		free(*arr);
		*arr = NULL;
	}
}

char	*error_message(int code)
{
	if (code == EXIT_FAILURE)
		return ("General error");
	else if (code == MALLOC_FAIL)
		return ("Memory allocation failed");
	else if (code == WRONG_INPUT)
		return ("Wrong input");
	else if (code == CANNOT_OPEN_FILE)
		return ("Unable to open the file");
	else
		return ("Unknown error");
}

void	safe_exit(t_var *data, int error_code)
{
	if (error_code != 0)
		perror(error_message(error_code));
	if (data)
	{
		if (data->display)
		{
			if (data->window)
				mlx_destroy_window(data->display, data->window);
			if (data->image.img)
				mlx_destroy_image(data->display, data->image.img);
			mlx_destroy_display(data->display);
			free(data->display);
		}
		if (data->content)
			ft_free(&data->content);
 		if (data->str_map)
			char_array_free(&data->str_map);
		if (data->map)
			array_free(&data->map);
		if (data->map_2d)
			array_free(&data->map_2d);
		if (data->line)
			char_array_free(&data->line);
		free(data);
	}
	exit(error_code);
}

int	ft_max(int count, ...)
{
	va_list	numbers;
	int		max;
	int		num;

	va_start(numbers, count);
	max = va_arg(numbers, double);
	while (--count > 0)
	{
		num = va_arg(numbers, double);
		if (num > max)
			max = num;
	}
	va_end(numbers);
	return (max);
}