/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 21:31:12 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/20 21:38:47 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
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

int     main(void)
{
        printf("Original:%d\n", strncmp("Hola", "Hola", 3));
        printf("ft_strcmp:%d\n\n", ft_strncmp("Hola", "Hola", 3));
        printf("Original:%d\n", strncmp("Holz", "Hola", 4));
        printf("ft_strcmp:%d\n\n", ft_strncmp("Holz", "Hola", 4));
        printf("Original:%d\n", strncmp("Hola", "Holz", 4));
        printf("ft_strcmp:%d\n\n", ft_strncmp("Hola", "Holz", 4));
	printf("Original:%d\n", strncmp("Hola", "Holz", 2));
        printf("ft_strcmp:%d\n", ft_strncmp("Hola", "Holz", 2));
        return (0);
}
*/
