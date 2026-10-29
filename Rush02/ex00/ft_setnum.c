/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 21:32:34 by nahardan          #+#    #+#             */
/*   Updated: 2026/10/25 22:49:00 by nahardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_scale(int th, char **dict, char **res)
{
	char	key[40];
	int		i;

	if (th == 0)
		return (1);
	if (th > 12)
		return (0);
	key[0] = '1';
	i = 1;
	while (i <= th * 3)
		key[i++] = '0';
	key[i] = '\0';
	return (ft_add_key(dict, key, res));
}

int	ft_walk(char *num, int th, char **dict, char **result)
{
	int	n;
	int	r;

	n = ft_dict_strlen(num) - th * 3;
	while (th >= 0)
	{
		r = ft_whole(num, dict, result);
		if (r)
			return (r > 0);
		if (!ft_is_zero(num, n) && !(ft_group(num, n, dict, result)
				&& ft_scale(th, dict, result)))
			return (0);
		num += n;
		n = 3;
		th--;
	}
	return (1);
}

int	ft_setnum(char *num, char **dict, char **result)
{
	int	ok;

	*result = NULL;
	while (*num == '0' && num[1])
		num++;
	if (*num == '0')
		return (ft_add_key(dict, "0", result));
	ok = ft_walk(num, (ft_dict_strlen(num) - 1) / 3, dict, result);
	if (!ok)
	{
		free(*result);
		*result = NULL;
	}
	return (ok);
}
