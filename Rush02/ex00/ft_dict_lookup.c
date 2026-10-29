/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_lookup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandreev <pandreev@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 10:38:22 by pandreev          #+#    #+#             */
/*   Updated: 2026/10/25 15:00:00 by pandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
 * Example: ft_dict_get(dict, "20") returns "twenty" in the reference dict.
 * Return NULL if the key is missing. Do not free the returned value.
 * The array stores key, value, key, value, ..., NULL.
 * dict[i + 1] is the value after the matching key at dict[i].
 * i += 2 skips the value and moves to the next key.
 */
char	*ft_dict_get(char **dict, const char *key)
{
	size_t	i;

	if (!dict)
		return (NULL);
	if (!key)
		return (NULL);
	i = 0;
	while (dict[i])
	{
		if (ft_dict_equal(dict[i], key))
			return (dict[i + 1]);
		i += 2;
	}
	return (NULL);
}

void	ft_dict_free(char **dict)
{
	size_t	i;

	if (!dict)
		return ;
	i = 0;
	while (dict[i])
	{
		free(dict[i]);
		i++;
	}
	free(dict);
}

/* Check a range of required keys, advancing by step each time. */
int	ft_required_range(char **dict, unsigned int first,
		unsigned int last, unsigned int step)
{
	unsigned int	number;
	char			key[4];

	number = first;
	while (number <= last)
	{
		ft_dict_number_key(number, key);
		if (!ft_dict_get(dict, key))
			return (0);
		number += step;
	}
	return (1);
}

/* Require reference scale keys: 1000, 1000000, ..., 10 to the power 36. */
int	ft_dict_required(char **dict)
{
	char	key[38];
	int		zeros;

	if (!ft_required_range(dict, 0, 19, 1))
		return (0);
	if (!ft_required_range(dict, 20, 100, 10))
		return (0);
	key[0] = '1';
	zeros = 1;
	while (zeros <= 36)
	{
		key[zeros] = '0';
		key[zeros + 1] = '\0';
		if (zeros % 3 == 0)
		{
			if (!ft_dict_get(dict, key))
				return (0);
		}
		zeros++;
	}
	return (1);
}
