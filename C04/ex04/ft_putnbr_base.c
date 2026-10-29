/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 21:24:52 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/29 21:49:09 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_base_conv(long nbr, int size, char *base)
{
	if (nbr >= size)
		ft_base_conv(nbr / size, size, base);
	write (1, &base[nbr % size], 1);
}

int	ft_check_base(char *base)
{
	int	size;
	int	check;

	size = 0;
	check = 0;
	while (base[size])
	{
		if (base[size] == '+' || base[size] == '-')
			return (0);
		check = 0;
		while (base[check])
		{
			if (check != size && base[check] == base[size])
				return (0);
			check++;
		}
		size++;
	}
	return (size);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	long	num;

	num = nbr;
	if (*base == 0)
		return ;
	size = ft_check_base(base);
	if (size < 2)
		return ;
	if (nbr < 0)
	{
		write (1, "-", 1);
		num = -num;
	}
	ft_base_conv(num, size, base);
}
/*
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}
*/
