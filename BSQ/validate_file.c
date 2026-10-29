/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangarci <jangarci@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:05:06 by jangarci          #+#    #+#             */
/*   Updated: 2026/10/28 21:24:34 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns the length of the line starting at *pos, moves *pos past '\n'
int	len_line(char *buf, int *pos)
{
	int	i;

	if (buf[*pos] == '\0')
		return (-1);
	i = 0;
	while (buf[*pos] && buf[*pos] != '\n')
	{
		i++;
		(*pos)++;
	}
	if (buf[*pos] == '\n')
		(*pos)++;
	return (i);
}

// body = map without the header line. Returns number of rows, 0 if invalid
int	len_rows(char *body)
{
	int	pos;
	int	y;
	int	len;
	int	ref;

	pos = 0;
	ref = len_line(body, &pos);
	if (ref <= 0)
		return (0);
	y = 1;
	len = len_line(body, &pos);
	while (len >= 0)
	{
		if (len != ref)
			return (0);
		y++;
		len = len_line(body, &pos);
	}
	return (y);
}

// header = digits followed by the 3 chars. Returns n, sets *pos after '\n'
int	ft_cabezera(char *buf, char *cells, int *pos)
{
	int	len;
	int	i;
	int	n;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (buf[len] != '\n' || len < 4)
		return (0);
	n = 0;
	i = -1;
	while (++i < len - 3)
	{
		if (buf[i] < '0' || buf[i] > '9')
			return (0);
		n = n * 10 + (buf[i] - '0');
	}
	cells[0] = buf[len - 3];
	cells[1] = buf[len - 2];
	cells[2] = buf[len - 1];
	*pos = len + 1;
	return (n);
}

void	fill_map(char *body, char **map, int row, int col)
{
	int	x;
	int	y;

	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			map[y][x] = body[y * (col + 1) + x];
			x++;
		}
		y++;
	}
}
