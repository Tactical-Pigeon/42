/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 21:39:50 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/20 21:57:47 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < nb)
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

	printf("Original:\n%s\n", strncat(test, "World!", 3));
	printf("ft_strcat:\n%s", ft_strncat(dest, "World!", 3));
}
*/
