/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 21:39:50 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/20 21:49:55 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char dest[100] = "Hello ";
	char test[100] = "Hello "; 

	printf("Original:\n%s\n", strcat(test, "World!"));
	printf("ft_strcat:\n%s", ft_strcat(dest, "World!"));
}
*/
