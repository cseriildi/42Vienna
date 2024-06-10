/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:23:36 by cseriildii        #+#    #+#             */
/*   Updated: 2024/06/09 10:51:35 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(t_var	*data)
{
	char	*line;
	char	*tmp;
	int		fd;
	
	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Could not open file", 2);
		exit(2);
	}
	data->content = get_next_line(fd);
	if (!data->content)
	{
		ft_putendl_fd("File is empty or other error occoured during get_next_line", 2);
		exit(3);
	}
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(data->content, line);
		free(data->content);
		free(line);
		data->content = tmp;
		line = get_next_line(fd);
	}
	close(fd);
}

void	check_input(t_var	*data)
{
	int	len;
	int	i;

	len = ft_strlen(data->content);
	if (len == 0 || data->content[len - 1] != '\n' || !ft_isdigit(data->content[0])
		|| ft_strnstr(data->content, "  ", len) || ft_strnstr(data->content, "\n ", len)
		|| ft_strnstr(data->content, " \n", len))
		exit (1);
	i = 0;
	while (++i < len)
	{
		if (!ft_isdigit(data->content[i]) && data->content[i] != ' ' && data->content[i] != '\n')
			exit (1);
	}
}

void	get_size(t_var	*data)
{
	char **line;
	
	data->height = 0;
	while (data->str_map[data->height])
		data->height++;
	line = ft_split(data->str_map[0], ' ');
	if (!line)
	{
		free(data->str_map);
		free(data->map);
		ft_putendl_fd("Error occoured during ft_split", 2);
		exit(3);
	}
	data->width = 0;
	while (line[data->width])
		data->width++;
}


void	create_map(t_var	*data)
{
	char	**line;
	int		i;
	int		j;

	data->str_map = ft_split(data->content, '\n');
	free(data->content);
	if (!data->str_map)
	{
		ft_putendl_fd("Error occoured during ft_split", 2);
		exit(3);
	}
	get_size(data);
	data->map = malloc(sizeof(int *) * data->height);
	if (!data->map)
	{
		free(data->str_map);
		ft_putendl_fd("Malloc failed", 2);
		exit(3);
	}
	i = 0;
	while (i < data->height)
	{
		line = ft_split(data->str_map[i], ' ');
		if (!line)
		{
			free(data->str_map); //this has to be in a loop to free all elements
			free(data->map);
			ft_putendl_fd("Error occoured during ft_split", 2);
			exit(3);
		}
		data->map[i] = malloc(sizeof(int) * data->width);
		if (!data->map[i])
		{
			free(line);
			free(data->str_map); //this has to be in a loop to free all elements
			free(data->map); //this has to be in a loop to free all elements
			ft_putendl_fd("Error occoured during ft_split", 2);
			exit(3);
		}
		j = 0;
		while (line[j] && j < data->width)
		{
			data->map[i][j] = ft_atoi(line[j]);
			j++;
		}
		if (j != data->width || line[j])
			exit(3);
		i++;
	}
	


}

void	parsing(t_var	*data)
{
	read_file(data);
	check_input(data);
	create_map(data);
}