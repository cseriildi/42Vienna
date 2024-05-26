/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:14:03 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/25 20:08:48 by cseriildii       ###   ########.fr       */
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

char	*error_message(int code)
{
	if (code == ERROR_MISUSE)
		return ("The number of arguments are incorrect");
	else if (code == CANNOT_OPEN_FILE)
		return ("Unable to open the file");
	else if (code == MALLOC_FAIL)
		return ("Memory allocation failed");
	else if (code == MISSING_PATH)
		return ("PATH not found");
	else if (code == PIPE_FAIL)
		return ("Pipe failed");
	else if (code == DUP2_FAIL)
		return ("Duplication failed");
	else if (code == FORK_FAIL)
		return ("Fork failed");
	else if (code == ERROR_CANNOT_EXECUTE)
		return ("Command found but not executable");
	else if (code == COMMAND_NOT_FOUND)
		return ("Command not found");
	else
		return ("Unknown error");
}

void	elegant_exit(t_var *data, int error_code)
{
	perror(error_message(error_code));
	if (data->path)
		array_free(&data->path);
	if (data->args)
		array_free(&data->args);
	if (data->absolut_cmd)
		ft_free(&data->absolut_cmd);
	if (data->pipe_fd[0] != -1)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] != -1)
		close(data->pipe_fd[1]);
	close(data->infile_fd);
	close(data->outfile_fd);
	if (data)
		free(data);
	exit(error_code);
}
