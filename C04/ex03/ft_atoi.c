/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:57:13 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/29 12:50:17 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg++;
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if (neg % 2 != 0)
		num = -num;
	return (num);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_atoi("   \r\v\f  \t  ---+--+1234ab567"));
	return (0);
}
*/
