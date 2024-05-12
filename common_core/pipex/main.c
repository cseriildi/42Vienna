/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:53:45 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/12 20:22:48 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*infile;
	char	*outfile;
	char	*command;
	int		i;

	if (argc  < 5)
		return (perror("Not enough parameters\n"), 1);
	infile = argv[1];
	outfile = argv[argc - 1];
	i = 2;
	while (i < argc - 1)
	{
		command = argv[i++];
	}
	if (access(infile, F_OK) == -1)
		return (perror("Infile does not exist\n"), 1);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		return (perror("Infile exists but not readable\n"), 1);
	close(fd);
	fd = open(outfile, O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		return (1);
	close(fd);
	}