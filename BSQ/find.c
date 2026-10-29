/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <gelorza@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:06:39 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/28 14:07:44 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putx(char **map, char *cells, int *ints)
{
	ints[2] = ints[5];
	ints[1] = ints[6];
	while (ints[2] < ints[4] + ints[5])
	{
		while (ints[1] < ints[4] + ints[6])
		{
			map[ints[2]][ints[1]] = cells[2];
			ints[1]++;
		}
		ints[1] = ints[6];
		ints[2]++;
	}
}

int	ft_obstaclecolumn(char **matrix, char validspace, int *ints)
{
	int	i;

	i = 0;
	while (i <= ints[0])
	{
		if (matrix[ints[2] + i][ints[1] + ints[0]] != validspace)
			return (0);
		i++;
	}
	return (1);
}

int	ft_obstacleline(char *line, char validspace, int *ints)
{
	int	i;

	i = 0;
	while (i <= ints[0])
	{
		if (line[ints[1] + i] != validspace)
			return (0);
		i++;
	}
	return (1);
}

int	ft_square(char **map, char *cells, int *ints)

{
	ints[0] = 0;
	while (ints[2] + ints[0] < ints[7]
		&& ints[1] + ints[0] < ints[8]
		&& ft_obstacleline(map[ints[2] + ints[0]], cells[0], ints) == 1
		&& ft_obstaclecolumn(map, cells[0], ints) == 1)
		ints[0]++;
	return (ints[0]);
}

//Array of ints
//[0] == i
//[1] == x
//[2] == y
//[3] == square
//[4] == maxsquare
//[5] == besty
//[6] == bestx
//[7] == maxy
//[8] == length

void	ft_find(char **map, char *cells, int maxy, int length)
{
	int	ints[9];

	ints[8] = 0;
	while (ints[8]++ < 7)
		ints[ints[8]] = 0;
	ints[7] = maxy;
	ints[8] = length;
	while (ints[2] < maxy)
	{
		ints[1] = 0;
		while (ints[1] < length)
		{
			if (map[ints[2]][ints[1]] == cells[0])
				ints[3] = ft_square(map, cells, ints);
			if (ints[3] > ints[4])
			{
				ints[4] = ints[3];
				ints[5] = ints[2];
				ints[6] = ints[1];
			}
			ints[1]++;
		}
		ints[2]++;
	}
	ft_putx(map, cells, ints);
}
