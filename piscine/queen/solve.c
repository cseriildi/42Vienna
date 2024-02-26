/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:00:24 by pvass             #+#    #+#             */
/*   Updated: 2024/02/24 14:06:07 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_sol(int board[6][6], int n)
{
	int	i;
	int	j;
	int count;

	i = 1;
	j = 1;
	count  = 0;
	while (i <= n)
	{
		while (j <= n)
		{
			if (board[i][j] == 1)
				count++;
			j++;
		}
		j = 1;
		i++;
	}
	if (count == 4)
		return (1);
	else 
		return (0);
	
}

int check_next(int board[6][6], int row, int col)
{
	int i;

	i = 1;
	while (i <= 4)
	{
		if (board[i][col] == 1 || board[row][i] == 1)
			return (0);
		i++;
	}
	return (1);
}

void print_sol(int board[6][6])
{
	int i;
	int j;
	char c;

	i = 1;
	j = 1;
	while (i <= 4)
	{
		while (j <= 4)
		{
			c = board[i][j] + 48;
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 1;
	}
	write(1, "\n", 1);
}

int solve(int board[6][6], int row , int col)
{
	int i;
	int j;

	j = col;
	i = row;
	if (check_sol(board, 4) == 1)
	{
		print_sol(board);
		return (0);
	}
	while (i <= 4)
	{
		while (j <= 4)
		{
			if (check_next(board, i, j) == 1)
			{
				board[i][j] = 1;
				solve(board, i, j);
				board[i][j] = 0;
			}
			j++;
		}
		i++;
		j = 1;
	}
	return (0);
}
