/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:14:03 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/29 18:45:25 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	array_free(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
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

void	safe_close(int fd)
{
	if (fd != -1)
		close(fd);
	fd = -1;
}

int	safe_open(char *filename, char mode, t_var *data)
{
	int	fd;

	fd = -1;
	if (mode == 'R')
		fd = open(filename, O_RDONLY, 0777);
	else if (mode == 'W')
		fd = open(filename, O_WRONLY, 0777);
	else if (mode == 'C')
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (mode == 'A')
		fd = open(filename, O_WRONLY | O_APPEND, 0777);
	else
		elegant_exit(data, ERROR_MISUSE);
	if (fd == -1)
		elegant_exit(data, CANNOT_OPEN_FILE);
	return (fd);
}

void	create_process(t_var *data, int fd[2])
{
	if (pipe(fd) == -1)
		elegant_exit(data, PIPE_FAIL);
	data->pid = fork();
	if (data->pid == -1)
		elegant_exit(data, FORK_FAIL);
}
