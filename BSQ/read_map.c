/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <gelorza@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 21:22:12 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/28 21:33:45 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**create_map(int row, int col)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * row);
	if (!map)
		return (NULL);
	i = 0;
	while (i < row)
	{
		map[i] = malloc(col);
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

void	free_map(char **map, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(map[i++]);
	free(map);
}

void	print_map(char **map, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		write(1, map[i], col);
		write(1, "\n", 1);
		i++;
	}
}

char	*ft_grow(char *old, int size, int cap)
{
	char	*new;
	int		i;

	new = malloc(cap + 1);
	if (!new)
	{
		free(old);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new[i] = old[i];
		i++;
	}
	new[size] = '\0';
	free(old);
	return (new);
}

char	*ft_read_all(int fd)
{
	char	*buf;
	int		size;
	int		cap;
	int		ret;

	size = 0;
	cap = 4096;
	buf = ft_grow(NULL, 0, cap);
	ret = 1;
	while (buf && ret > 0)
	{
		ret = read(fd, buf + size, cap - size);
		if (ret > 0)
			size += ret;
		if (ret > 0)
			buf[size] = '\0';
		if (ret > 0 && size == cap)
			buf = ft_grow(buf, size, cap *= 2);
	}
	if (ret < 0)
		free(buf);
	if (ret < 0)
		return (NULL);
	return (buf);
}
