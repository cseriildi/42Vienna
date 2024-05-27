/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:15:55 by icseri            #+#    #+#             */
/*   Updated: 2024/05/27 18:21:38 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_var *data)
{
	data->pid = -1;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->tmp_pipe[0] = -1;
	data->tmp_pipe[1] = -1;
	data->i_fd = -1;
	data->limiter = NULL;
	data->o_fd = -1;
	data->commands = NULL;
	data->absolut_cmd = NULL;
	data->args = NULL;
	data->path = NULL;
	data->env = NULL;
}

void	parse_input(t_var *data, int count, char **params, char **env)
{
	int		i;

	i = 1;
	init_data(data);
	data->infile = params[i++];
	data->outfile = params[count - 1];
	data->cmd_count = count - 3;
	if (ft_strncmp(data->infile, "here_doc", 9) == 0)
	{
		data->limiter = ft_strjoin(params[i++], "\n");
		if (!data->limiter)
			elegant_exit(data, MALLOC_FAIL);
		data->cmd_count--;
	}
	data->commands = params + i;
	data->commands[data->cmd_count] = NULL;
	data->env = env;
	i = 0;
	while (data->env[i] && ft_strncmp(data->env[i], "PATH=", 5) != 0)
		i++;
	if (!data->env[i])
		elegant_exit(data, MISSING_PATH);
	data->path = ft_split(data->env[i] + 5, ':');
	if (!data->path)
		elegant_exit(data, MALLOC_FAIL);
}

char	*find_path(t_var *data)
{
	int		i;
	char	*abs_cmd;

	i = -1;
	while (data->path[++i])
	{
		abs_cmd = ft_strjoin2(data->path[i], data->cmd, "/");
		if (!abs_cmd)
			elegant_exit(data, MALLOC_FAIL);
		if (access(abs_cmd, F_OK) == 0)
			return (abs_cmd);
		free(abs_cmd);
	}
	return (NULL);
}
