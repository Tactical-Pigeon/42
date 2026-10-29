/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandreev <pandreev@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 00:18:42 by pandreev          #+#    #+#             */
/*   Updated: 2026/10/25 15:00:00 by pandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_valid_chunk(const char *chunk, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (chunk[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/* Copy the old string first, then the chunk, then terminate the result. */
void	ft_copy_joined(char *joined, const char *buffer,
		const char *chunk, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i])
	{
		joined[i] = buffer[i];
		i++;
	}
	j = 0;
	while (j < size)
	{
		joined[i] = chunk[j];
		i++;
		j++;
	}
	joined[i] = '\0';
}

/* Free the old buffer after appending, including when appending fails. */
char	*ft_append_chunk(char *buffer, const char *chunk, size_t size)
{
	char	*joined;
	size_t	length;

	joined = NULL;
	if (ft_valid_chunk(chunk, size))
	{
		length = ft_dict_strlen(buffer);
		joined = ft_join_alloc(length, size);
		if (joined)
			ft_copy_joined(joined, buffer, chunk, size);
	}
	free(buffer);
	return (joined);
}

char	*ft_read_chunks(int fd)
{
	char	chunk[4096];
	char	*buffer;
	ssize_t	size;

	buffer = malloc(1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	size = read(fd, chunk, sizeof(chunk));
	while (size > 0)
	{
		buffer = ft_append_chunk(buffer, chunk, (size_t)size);
		if (!buffer)
			return (NULL);
		size = read(fd, chunk, sizeof(chunk));
	}
	if (size < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_dict_read(const char *path)
{
	int		fd;
	char	*buffer;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = ft_read_chunks(fd);
	if (close(fd) < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
