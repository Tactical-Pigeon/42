/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 21:19:37 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/20 21:39:35 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	printf("Original:%d\n", strcmp("Hola", "Hola"));
	printf("ft_strcmp:%d\n\n", ft_strcmp("Hola", "Hola"));
	printf("Original:%d\n", strcmp("Holz", "Hola"));
        printf("ft_strcmp:%d\n\n", ft_strcmp("Holz", "Hola"));
	printf("Original:%d\n", strcmp("Hola", "Holz"));
        printf("ft_strcmp:%d\n", ft_strcmp("Hola", "Holz"));
	return (0);
}
*/
