/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:27:07 by icseri            #+#    #+#             */
/*   Updated: 2024/06/14 17:10:14 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int	fd)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->content = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}


static char	*read_fd(int fd, char *read_chars)
{
	char		*tmp;
	char		*buffer;
	long		read_size;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (ft_free(&read_chars), NULL);
	read_size = 1;
	while (read_size > 0 && is_nl(read_chars) == 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (ft_free(&buffer), ft_free(&read_chars), NULL);
		buffer[read_size] = '\0';
		tmp = ft_strjoin(read_chars, buffer);
		ft_free(&read_chars);
		read_chars = tmp;
		if (!read_chars)
			return (ft_free(&buffer), ft_free(&read_chars), NULL);
	}
	ft_free(&buffer);
	if (!read_chars || !read_chars[0])
		return (ft_free(&read_chars), NULL);
	return (read_chars);
}

char	*get_next_line(int fd)
{
	static t_list	**list;
	t_list			*read_chars;
	char			*line;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_chars = NULL;
	if (list)
		read_chars = *list;
	while (read_chars && read_chars->fd != fd)
		read_chars = read_chars->next;
	if (read_chars == NULL)
	{
		list = malloc(sizeof(t_list));
		ft_lstadd_front(list, ft_lstnew(fd));
	}
	read_chars->content = read_fd(fd, read_chars->content);
	if (!read_chars->content)
		return (ft_free(&read_chars->content), NULL);
	line = line_search(read_chars->content);
	if (!line || !*line)
		return (ft_free(&read_chars->content), ft_free(&line), NULL);
	tmp = ft_strjoin(NULL, read_chars->content + ft_strlen(line));
	ft_free(&read_chars->content);
	read_chars->content = tmp;
	if (!read_chars->content)
		return (ft_free(&line), ft_free(&read_chars->content), NULL);
	return (line);
}

# include <fcntl.h>
# include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (-1);
	fd2 = open("test.txt", O_RDWR);
	if (fd2 == -1)
		return (-1);
	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	while (line || line2)
	{
		if (line)
		{
			printf("[%s]\n", line);
			free(line);
			line = get_next_line(fd);
		}
		if (line2)
		{
			printf("[%s]\n", line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
	}
	close(fd);
}