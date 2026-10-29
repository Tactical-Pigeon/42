/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <gelorza@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:33:59 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/29 13:18:11 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnum(long n)
{
	char	c;

	if (n >= 10)
		ft_putnum(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
	}
	ft_putnum(n);
}
/*
int	main(void)
{
        ft_putnbr(42);
        write(1, "\n", 1);
        ft_putnbr(-89);
        write(1, "\n", 1);
        ft_putnbr(300);
        write(1, "\n", 1);
        ft_putnbr(-10);
        write(1, "\n", 1);
        ft_putnbr(2147483647);
        write(1, "\n", 1);
	ft_putnbr(-2147483648);
	return (0);
}
*/
