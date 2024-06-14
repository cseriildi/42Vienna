/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:48:54 by icseri            #+#    #+#             */
/*   Updated: 2024/06/14 11:50:22 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_esc(int key, t_var *data)
{
	if (key == ESC)
		safe_exit(data, EXIT_SUCCESS);
	return (0);
}

int	handle_close(t_var *data)
{
	safe_exit(data, EXIT_SUCCESS);
	return (0);
}