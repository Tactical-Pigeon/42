/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <gelorza@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 22:36:15 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/28 22:37:19 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_valid_cells(char *cells)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (cells[i] < 32 || cells[i] > 126)
			return (0);
		i++;
	}
	if (cells[0] == cells[1] || cells[0] == cells[2] || cells[1] == cells[2])
		return (0);
	return (1);
}

int	ft_valid_map(char **map, char *cells, int row, int col)
{
	int	y;
	int	x;

	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			if (map[y][x] != cells[0] && map[y][x] != cells[1])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
