/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:44:32 by swijnber          #+#    #+#             */
/*   Updated: 2022/02/23 13:43:31 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	possible2(int grid[10][10], int x, int y)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (++i < 10 && --j > -1)
		if (grid[i][j])
			return (0);
	while (--y > -1 && ++x < 10)
		if (grid[y][x])
			return (0);
	return (1);
}

int	possible(int grid[10][10], int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
		if (grid[i][x] || grid[y][i])
			return (0);
	i = y;
	j = x;
	while (++i < 10 && ++j < 10)
		if (grid[i][j])
			return (0);
	i = y;
	j = x;
	while (--i > -1 && --j > -1)
		if (grid[i][j])
			return (0);
	return (possible2(grid, x, y));
}

void	print_grid(int grid[10][10], int *c)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 10)
	{
		i = -1;
		while (++i < 10)
		{
			if (grid[i][j])
			{
				i = i + '0';
				write (1, &i, 1);
			}
		}
	}
	write (1, "\n", 1);
	*c += 1;
}

void	solve_grid(int grid[10][10], int *c, int x)
{
	int	y;

	x = -1;
	while (++x < 10)
	{
		y = -1;
		while (++y < 10)
		{
			if (!grid [y][x] && possible(grid, x, y))
			{
				grid[y][x] = 1;
				solve_grid(grid, c, x);
				grid[y][x] = 0;
			}
		}
		y = -1;
		while (++y < 10)
		{
			if (grid[y][x])
				break ;
			if (y == 9)
				return ;
		}
	}
	print_grid(grid, c);
}

int	ft_ten_queens_puzzle(void)
{
	int	grid[10][10];
	int	c;
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = 0;
		while (j < 10)
			grid [i][j++] = 0;
	}
	c = 0;
	solve_grid(grid, &c, i);
	return (c);
}
