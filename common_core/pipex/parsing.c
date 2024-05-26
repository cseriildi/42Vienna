/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:15:55 by icseri            #+#    #+#             */
/*   Updated: 2024/05/26 15:22:31 by cseriildii       ###   ########.fr       */
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
	data->absolut_cmd = NULL;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
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
