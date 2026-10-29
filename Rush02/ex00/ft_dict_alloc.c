/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandreev <pandreev@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 07:16:31 by pandreev          #+#    #+#             */
/*   Updated: 2026/10/25 15:00:00 by pandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/* Every slot starts as NULL so cleanup also works after a failed copy. */
void	ft_clear_slots(char **dict, size_t slots)
{
	size_t	i;

	i = 0;
	while (i < slots)
	{
		dict[i] = NULL;
		i++;
	}
}

/*
 * SIZE_MAX is the largest size_t value, used to represent sizes in bytes.
 * Divide by the size of a pointer to find the maximum number of slots.
 * Reserve one NULL slot, then divide by two: each entry is key + value.
 * This prevents arithmetic overflow; malloc can still fail afterward.
 */
char	**ft_create_dict(size_t count)
{
	char	**dict;
	size_t	max_slots;
	size_t	max_entries;
	size_t	slots;

	if (count == 0)
		return (NULL);
	max_slots = SIZE_MAX / sizeof(char *);
	max_entries = max_slots - 1;
	max_entries = max_entries / 2;
	if (count > max_entries)
		return (NULL);
	slots = count * 2;
	slots++;
	dict = malloc(slots * sizeof(char *));
	if (!dict)
		return (NULL);
	ft_clear_slots(dict, slots);
	return (dict);
}

/* Leave one available byte for the final '\0' before adding the sizes. */
char	*ft_join_alloc(size_t length, size_t chunk_size)
{
	size_t	available;
	size_t	total_size;

	available = SIZE_MAX - length;
	if (chunk_size >= available)
		return (NULL);
	total_size = length + chunk_size;
	total_size++;
	return (malloc(total_size));
}
