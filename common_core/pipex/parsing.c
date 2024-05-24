/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:15:55 by icseri            #+#    #+#             */
/*   Updated: 2024/05/24 18:25:34 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_input(t_var *data, int count, char **params, char **env)
{
	int		i;

	data->infile = params[1];
	data->outfile = params[count - 1];
	data->cmd_count = count - 3;
	data->commands = params + 2;
	data->commands[data->cmd_count] = NULL;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->env = env;
	i = 0;
	while (data->env[i] && ft_strncmp(data->env[i], "PATH=", 5) != 0)
		i++;
	if (!data->env[i])
		elegant_exit("PATH not found", data);
	data->path = ft_split(data->env[i] + 5, ':');
	if (!data->path)
		elegant_exit("Memory allocation failed", data);
}

void	find_path(t_var *data, int cmd_index)
{
	int		i;
	char	*abs_cmd;

	i = -1;
	while (data->path[++i])
	{
		abs_cmd = ft_strjoin2(data->path[i], data->commands[cmd_index], "/");
		if (!abs_cmd)
			elegant_exit("Memory allocation failed", data);
		if (access(abs_cmd, F_OK | X_OK) == 0)
		{
			data->absolut_cmd = abs_cmd;
			return ;
		}
		free(abs_cmd);
	}
	elegant_exit("Command does not exist", data);
}

void	set_command(t_var *data, int cmd_index)
{
	data->args = ft_split(data->commands[cmd_index], ' ');
	if (!data->args)
		elegant_exit("Memory allocation failed", data);
	data->cmd = data->args[0];
	if (access(data->cmd, F_OK | X_OK) == 0)
		data->absolut_cmd = data->cmd;
	else
		find_path(data, cmd_index);
}
