/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:21:07 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/09 10:45:19 by cseriildii       ###   ########.fr       */
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

/* void	safe_exit(t_var *data, int error_code)
{
	perror(error_message(error_code));
	if (data)
	{
		if (data->path)
			array_free(data->path);
		if (data->args)
			array_free(data->args);
		if (data->absolut_cmd)
			ft_free(&data->absolut_cmd);
		if (data->limiter)
			ft_free(&data->limiter);
		free(data);
	}
	exit(error_code);
}

 */