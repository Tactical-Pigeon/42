/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 21:33:03 by nahardan          #+#    #+#             */
/*   Updated: 2026/10/25 22:28:26 by nahardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	ft_group_digit(const char *g, int n, int pos)
{
	pos = pos - (3 - n);
	if (pos < 0)
		return ('0');
	return (g[pos]);
}

int	ft_is_zero(const char *g, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (g[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_hundreds(const char *g, int n, char **dict, char **res)
{
	char	key[2];

	key[0] = ft_group_digit(g, n, 0);
	key[1] = '\0';
	if (key[0] == '0')
		return (1);
	if (!ft_add_key(dict, key, res))
		return (0);
	return (ft_add_key(dict, "100", res));
}

int	ft_tens_units(const char *g, int n, char **dict, char **res)
{
	char	key[3];

	key[0] = ft_group_digit(g, n, 1);
	key[1] = ft_group_digit(g, n, 2);
	key[2] = '\0';
	if (key[0] == '1')
		return (ft_add_key(dict, key, res));
	if (key[0] != '0')
	{
		key[1] = '0';
		if (!ft_add_key(dict, key, res))
			return (0);
		key[1] = ft_group_digit(g, n, 2);
	}
	if (key[1] != '0')
	{
		key[0] = key[1];
		key[1] = '\0';
		return (ft_add_key(dict, key, res));
	}
	return (1);
}

int	ft_group(const char *g, int n, char **dict, char **res)
{
	char	key[4];
	int		i;
	int		j;

	i = 0;
	while (i < n - 1 && g[i] == '0')
		i++;
	j = 0;
	while (i < n)
		key[j++] = g[i++];
	key[j] = '\0';
	if (!ft_dict_equal(key, "100") && ft_dict_get(dict, key))
		return (ft_add_key(dict, key, res));
	return (ft_hundreds(g, n, dict, res) && ft_tens_units(g, n, dict, res));
}
