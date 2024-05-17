/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:53:45 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/17 14:11:38 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* int	main(int argc, char **argv)
{
	int		fd[2];
	int		pid;
	char	*infile;
	char	*outfile;
	char	*command;
	int		i;

	if (argc  < 5)
		return (write(2, "Not enough parameters\n", 23), 1);
	if (pipe(fd) == -1)
		return (perror("Error occured while opening pipe\n"), 2);
	pid = fork();
	if (pid == -1) 
		return (perror("Error occured while forking\n"), 3);
	infile = argv[1];
	outfile = argv[argc - 1];
	i = 2;
	while (i < argc - 1)
	{
		command = argv[i++];
	}
	if (access(infile, F_OK) == -1)
		return (perror("Infile does not exist\n"), 2);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		return (perror("Infile exists but not readable\n"), 1);
	close(fd);
	fd = open(outfile, O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		return (1);
	close(fd);
	} */