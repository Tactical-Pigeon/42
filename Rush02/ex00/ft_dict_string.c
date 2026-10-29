/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandreev <pandreev@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 23:12:16 by pandreev          #+#    #+#             */
/*   Updated: 2026/10/25 15:00:00 by pandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

size_t	ft_dict_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

/* see also ft_strcmp */
int	ft_dict_equal(const char *left, const char *right)
{
	while (*left && *left == *right)
	{
		left++;
		right++;
	}
	return (*left == *right);
}

/* see also ft_strdup */
char	*ft_dict_dup(const char *str)
{
	char	*copy;
	size_t	i;

	copy = malloc(ft_dict_strlen(str) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/* Only used for the required keys from 0 through 100. */
void	ft_dict_number_key(unsigned int number, char *key)
{
	unsigned int	divisor;

	divisor = 1;
	while (number / divisor >= 10)
		divisor *= 10;
	while (divisor)
	{
		*key = '0' + number / divisor;
		key++;
		number %= divisor;
		divisor /= 10;
	}
	*key = '\0';
}
