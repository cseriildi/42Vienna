/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:21:07 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/11 16:09:04 by icseri           ###   ########.fr       */
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

 void	safe_exit(t_var *data, int error_code)
{
	perror(error_message(error_code));
	if (data)
	{
		if (data->mlx)
			mlx_destroy_display(data->mlx);
		if (data->window)
			mlx_destroy_display(data->window);
		free(data);
	}
	exit(error_code);
}

