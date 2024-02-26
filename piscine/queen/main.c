/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:13:47 by pvass             #+#    #+#             */
/*   Updated: 2024/02/24 13:48:29 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int solve (int board[6][6], int row, int col);

void create_grid(int input[16], int grid[6][6]);

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	check_input(char *argv)
{
	int i;
	int	sum;

	sum = 0;
	i = 0;
	if(ft_strlen(argv) != 31)
		return (0);
	while (argv[i + 1] != '\0')
		{
			sum = sum + argv[i] - 48;
			i += 2;
		}
	sum = sum + argv[i] - 48;
	if (sum != 34)
		return (0);
	return (1);
}

void transform(int input[], char *argv)
{
	int i;

	i = 0;
	while (*(argv + i + 1) != '\0')
	{
		input[i/2] = *(argv + i) - 48;
		i += 2;
	}
	input[i/2] = *(argv + i) - 48;
}

int	main(int argc, char **argv)
{
	int input[16];
	int i;
	int j;
	int grid[6][6];

	j = 0;
	i = 0;
	if (argc != 2)
	{
		write (1, "Wrong input\n", 12);
		return (0);
	}
	if (check_input(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	transform(input, argv[1]);
	create_grid(input, grid);
	/*
	while (i < 16)
	{
		printf("%d ", input[i]);
		i++;
	}

	while (i < 6)
	{
		while (j < 6)
		{	
			printf("%d ", grid[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
	*/
	solve(grid, 1, 1);
	return (0);
}
