/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:14:03 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/27 18:04:02 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(t_var *data, int cmd_index)
{
	data->args = ft_split(data->commands[cmd_index], ' ');
	if (!data->args)
		elegant_exit(data, MALLOC_FAIL);
	data->cmd = data->args[0];
	if (access(data->cmd, F_OK) == 0)
		data->absolut_cmd = data->cmd;
	else
		data->absolut_cmd = find_path(data);
	if (execve(data->absolut_cmd, data->args, data->env) == -1)
	{
		if (data->absolut_cmd == NULL)
			elegant_exit(data, COMMAND_NOT_FOUND);
		else
			elegant_exit(data, ERROR_CANNOT_EXECUTE);
	}
}

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
	else if (code == UNLINK_FAIL)
		return ("Can not delete file");
	else
		return ("Unknown error");
}

void	elegant_exit(t_var *data, int error_code)
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
		if (data->pipe_fd[0] != -1)
			close(data->pipe_fd[0]);
		if (data->pipe_fd[1] != -1)
			close(data->pipe_fd[1]);
		if (data->i_fd != -1)
			close(data->i_fd);
		if (data->o_fd != -1)
			close(data->o_fd);
		if (data->tmp_pipe[0] == -1)
			close(data->tmp_pipe[0]);
		if (data->tmp_pipe[1] == -1)
			close(data->tmp_pipe[1]);
		free(data);
	}
	exit(error_code);
}
