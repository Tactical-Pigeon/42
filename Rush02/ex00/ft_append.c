/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 21:34:15 by nahardan          #+#    #+#             */
/*   Updated: 2026/10/25 22:47:44 by nahardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	ft_fill_join(char *joined, const char *old, const char *word)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (old && old[i])
	{
		joined[i] = old[i];
		i++;
	}
	if (old)
		joined[i++] = ' ';
	j = 0;
	while (word[j])
		joined[i++] = word[j++];
	joined[i] = '\0';
}

int	ft_append_word(char **result, const char *word)
{
	char	*joined;
	size_t	len;

	len = 0;
	if (*result)
		len = ft_dict_strlen(*result) + 1;
	joined = malloc(len + ft_dict_strlen(word) + 1);
	if (!joined)
		return (0);
	ft_fill_join(joined, *result, word);
	free(*result);
	*result = joined;
	return (1);
}

int	ft_add_key(char **dict, const char *key, char **result)
{
	char	*word;

	word = ft_dict_get(dict, key);
	if (!word)
		return (0);
	return (ft_append_word(result, word));
}

int	ft_is_pow100(const char *s)
{
	int	i;

	if (s[0] != '1')
		return (0);
	i = 1;
	while (s[i] == '0')
		i++;
	return (s[i] == '\0' && i >= 3);
}

/* 0 = no existe, 1 = añadido, -1 = fallo de malloc */
int	ft_whole(const char *num, char **dict, char **result)
{
	while (*num == '0')
		num++;
	if (!*num || ft_is_pow100(num) || !ft_dict_get(dict, num))
		return (0);
	if (!ft_append_word(result, ft_dict_get(dict, num)))
		return (-1);
	return (1);
}
