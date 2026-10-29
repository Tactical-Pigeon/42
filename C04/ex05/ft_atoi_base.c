/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <gelorza@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:47:28 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/29 22:10:26 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_validbase(char *base)
{
	int	i;
	int	check;

	i = 0;
	if (*base == 0)
		return (-1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n'
			|| base[i] == '\r' || base[i] == '\v' || base[i] == '\f')
			return (-1);
		check = 0;
		while (base[check])
		{
			if (check != i && base[check] == base[i])
				return (-1);
			check++;
		}
		i++;
	}
	return (i);
}

int	ft_power(int pow, int pos)
{
	int	i;
	int	value;

	i = 0;
	value = 1;
	while (i < pos)
	{
		if (value == 1)
			value = pow;
		else
			value *= pow;
		i++;
	}
	return (value);
}

int	ft_putnum_base(char *str, int size, char *base, int basesize)
{
	int	i;
	int	num;
	int	pow;
	int	value;

	i = 0;
	num = 0;
	while (i < size)
	{
		value = ft_isbase(str[i], base);
		pow = ft_power(basesize, size - 1 - i);
		num += value * pow;
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	neg;
	int	num;

	i = 0;
	j = 0;
	neg = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg++;
	while (ft_isbase(str[i + j], base) >= 0)
		j++;
	num = ft_validbase(base);
	if (num < 2)
		return (0);
	num = ft_putnum_base(str + i, j, base, num);
	if (neg % 2 != 0)
		num = -num;
	return (num);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", ft_atoi_base(argv[1], argv[2]));
	return (0);
}
*/
