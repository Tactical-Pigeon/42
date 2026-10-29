/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangarci <jangarci@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 23:18:08 by jangarci          #+#    #+#             */
/*   Updated: 2026/10/28 22:41:46 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_error(void)
{
	write(1, "map error\n", 10);
	return (1);
}

void	ft_print_solution(char **map, char *cells, int row, int col)
{
	if (!ft_valid_map(map, cells, row, col))
	{
		ft_error();
		return ;
	}
	ft_find(map, cells, row, col);
	print_map(map, row, col);
}

void	ft_solve(char *buf)
{
	char	cells[4];
	char	**map;
	int		row;
	int		col;
	int		pos;

	row = ft_cabezera(buf, cells, &pos);
	if (row == 0 || !ft_valid_cells(cells)
		|| len_rows(buf + pos) != row)
	{
		ft_error();
		return ;
	}
	buf += pos;
	pos = 0;
	col = len_line(buf, &pos);
	map = create_map(row, col);
	fill_map(buf, map, row, col);
	ft_print_solution(map, cells, row, col);
	free_map(map, row);
}

void	ft_file(char *path)
{
	int		fd;
	char	*buf;

	fd = 0;
	if (path)
		fd = open(path, O_RDONLY);
	buf = ft_read_all(fd);
	if (path && fd >= 0)
		close(fd);
	if (!buf)
		ft_error();
	else
		ft_solve(buf);
	free(buf);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_file(NULL);
	i = 1;
	while (i < argc)
	{
		ft_file(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
