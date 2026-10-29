/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandreev <pandreev@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 07:16:31 by pandreev          #+#    #+#             */
/*   Updated: 2026/10/25 15:00:00 by pandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
 * Count the first character of each nonempty line:
 * either i == 0 (the first line), or the previous character is '\n'.
 */
size_t	ft_count_entries(const char *buffer)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] != '\n')
		{
			if (i == 0)
				count++;
			else if (buffer[i - 1] == '\n')
				count++;
		}
		i++;
	}
	return (count);
}

char	*ft_next_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			break ;
		line++;
	}
	if (*line == '\n')
	{
		*line = '\0';
		line++;
	}
	return (line);
}

int	ft_fill_dict(char **dict, char *line)
{
	char	*next;
	size_t	slot;

	slot = 0;
	while (*line)
	{
		next = ft_next_line(line);
		if (*line)
		{
			if (!ft_dict_add(dict, slot, line))
				return (0);
			slot += 2;
		}
		line = next;
	}
	return (1);
}

/* Return the dictionary, or NULL on failure. Free it with ft_dict_free. */
char	**ft_parse_dict(const char *path)
{
	char	*buffer;
	char	**dict;
	size_t	count;
	int		valid;

	buffer = ft_dict_read(path);
	if (!buffer)
		return (NULL);
	count = ft_count_entries(buffer);
	dict = ft_create_dict(count);
	if (dict)
	{
		valid = ft_fill_dict(dict, buffer);
		if (valid)
			valid = ft_dict_required(dict);
		if (!valid)
		{
			ft_dict_free(dict);
			dict = NULL;
		}
	}
	free(buffer);
	return (dict);
}
