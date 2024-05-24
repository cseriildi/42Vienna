/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:14:03 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/24 13:44:12 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	array_free(char ***arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while ((*arr)[i])
			free((*arr)[i++]);
		free(*arr);
	}
}

void	elegant_exit(char *error_msg, char **arr1_to_free, char **arr2_to_free)
{
	if (arr1_to_free)
		array_free(&arr1_to_free);
	if (arr2_to_free)
		array_free(&arr2_to_free);
	perror(error_msg);
	exit(EXIT_FAILURE);
}

char	*ft_strjoin2(char *str1, char *str2, char *delimiter)
{
	char	*tmp;
	char	*new_str;

	tmp = ft_strjoin(str1, delimiter);
	if (!tmp)
		return (NULL);
	new_str = ft_strjoin(tmp, str2);
	free(tmp);
	if (!new_str)
		return (NULL);
	return (new_str);
}
