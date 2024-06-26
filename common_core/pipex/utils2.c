/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:00:52 by icseri            #+#    #+#             */
/*   Updated: 2024/06/26 13:27:10 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(t_var *data, int cmd_index)
{
	data->args = ft_split(data->commands[cmd_index], ' ');
	if (!data->args)
		elegant_exit(data, MALLOC_FAIL);
	data->cmd = data->args[0];
	if (access(data->cmd, X_OK) == 0)
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
	if (error_code != 0)
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
		safe_close(data->pipe[0]);
		safe_close(data->pipe[1]);
		safe_close(data->i_fd);
		safe_close(data->o_fd);
		safe_close(data->pipe2[0]);
		safe_close(data->pipe2[1]);
		free(data);
		data = NULL;
	}
	exit(error_code);
}
