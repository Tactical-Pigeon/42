/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandreev <pandreev@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 02:24:09 by pandreev          #+#    #+#             */
/*   Updated: 2026/10/25 15:00:00 by pandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*ft_key_end(char *line)
{
	char	*end;

	end = line;
	while (*end >= '0' && *end <= '9')
		end++;
	if (end == line)
		return (NULL);
	if (line[0] == '0')
	{
		if (end > line + 1)
			return (NULL);
	}
	return (end);
}

char	*ft_trim_value(char *value)
{
	char			*end;
	unsigned char	character;

	while (*value == ' ')
		value++;
	end = value;
	while (*end)
	{
		character = *end;
		if (character < 32)
			return (NULL);
		if (character > 126)
			return (NULL);
		end++;
	}
	while (end > value && end[-1] == ' ')
		end--;
	if (end == value)
		return (NULL);
	*end = '\0';
	return (value);
}

/*
 * Modify line so it contains a separate key string and value string.
 * Return a pointer to the trimmed value, or NULL for an invalid entry.
 * Colons inside the value remain unchanged. No memory is allocated here.
 */
char	*ft_split_entry(char *line)
{
	char	*end;
	char	*colon;
	char	*value;

	end = ft_key_end(line);
	if (!end)
		return (NULL);
	colon = end;
	while (*colon == ' ')
		colon++;
	if (*colon != ':')
		return (NULL);
	value = ft_trim_value(colon + 1);
	if (!value)
		return (NULL);
	*end = '\0';
	return (value);
}

/*
 * Return 0 if the line is invalid, the key already exists, or allocating
 * either the key copy or the value copy fails. Return 1 on success.
 * The caller frees the partially built dictionary on failure.
 */
int	ft_dict_add(char **dict, size_t slot, char *line)
{
	char	*value;

	value = ft_split_entry(line);
	if (!value)
		return (0);
	if (ft_dict_get(dict, line))
		return (0);
	dict[slot] = ft_dict_dup(line);
	if (!dict[slot])
		return (0);
	dict[slot + 1] = ft_dict_dup(value);
	if (!dict[slot + 1])
		return (0);
	return (1);
}
