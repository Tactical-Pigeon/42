/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:00:39 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/29 20:02:37 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	k = 0;
	while (src[j])
	{
		if (i + j + 1 < size)
		{
			dest[i + j] = src[j];
			k++;
		}
		j++;
	}
	if (i < size)
	{
		dest[i + k] = '\0';
		return (i + j);
	}
	return (size + j);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

#define CAP 64
#define GUARD 8
#define TOTAL (GUARD + CAP + GUARD)
#define MAX_REPORTS 15

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

static int	g_tests = 0;
static int	g_fail = 0;

static void	fill(unsigned char *mem, const char *dest)
{
	memset(mem, 0xAA, GUARD);
	memset(mem + GUARD, 'X', CAP);
	memset(mem + GUARD + CAP, 0xAA, GUARD);
	memcpy(mem + GUARD, dest, strlen(dest) + 1);
}

static void	show(const unsigned char *mem, int n)
{
	int	i;

	printf("[");
	for (i = 0; i < n; i++)
	{
		if (mem[GUARD + i] == '\0')
			printf(RED "0" RESET);
		else if (mem[GUARD + i] >= 32 && mem[GUARD + i] < 127)
			printf("%c", mem[GUARD + i]);
		else
			printf(".");
	}
	printf("]");
}

static int	guards_ok(const unsigned char *mem)
{
	int	i;

	for (i = 0; i < GUARD; i++)
		if (mem[i] != 0xAA || mem[GUARD + CAP + i] != 0xAA)
			return (0);
	return (1);
}

static int	run_case(const char *dest, const char *src, size_t size)
{
	unsigned char	actual[TOTAL];
	unsigned char	expected[TOTAL];
	unsigned int	ret_a;
	size_t			ret_e;
	int				ok_ret;
	int				ok_buf;
	int				ok_guard;
	int				n;

	fill(actual, dest);
	fill(expected, dest);
	ret_a = ft_strlcat((char *)actual + GUARD, (char *)src, (unsigned int)size);
	ret_e = strlcat((char *)expected + GUARD, src, size);
	ok_ret = (ret_a == ret_e);
	ok_buf = (memcmp(actual, expected, TOTAL) == 0);
	ok_guard = guards_ok(actual);
	g_tests++;
	if (ok_ret && ok_buf && ok_guard)
		return (1);
	if (g_fail < MAX_REPORTS)
	{
		n = (int)(strlen(dest) + strlen(src) + 4);
		if (n > CAP)
			n = CAP;
		printf("\n" RED "FAIL" RESET " dest=\"%s\" src=\"%s\" size=%zu\n",
			dest, src, size);
		printf("  mine:     ret=%u  ", ret_a);
		show(actual, n);
		printf("\n  expected: ret=%zu  ", ret_e);
		show(expected, n);
		printf("\n  problems:%s%s%s\n",
			ok_ret ? "" : " return-value",
			ok_buf ? "" : " buffer-content",
			ok_guard ? "" : " OUT-OF-BOUNDS-WRITE");
	}
	g_fail++;
	return (0);
}

static void	sweep(const char *dest, const char *src)
{
	size_t	size;
	int		bad;

	bad = 0;
	for (size = 0; size <= CAP; size++)
		bad += !run_case(dest, src, size);
	printf("%s dest=\"%s\" src=\"%s\"\n",
		bad ? RED "-" RESET : GREEN "+" RESET, dest, src);
}

int	main(void)
{
	sweep("Hello ", "World!");
	sweep("42dfgd", " l33r");
	sweep("toto", " bla");
	sweep("pouic", " pouic");
	sweep("", "Hello");
	sweep("Hello", "");
	sweep("", "");
	sweep("a", "b");
	sweep("123456789", "X");
	sweep("Hi", "A very long source string that never fits in small buffers");
	sweep("A long destination string already filling a lot", "ab");
	sweep("same", "same");
	printf("\n%d tests | ", g_tests);
	if (g_fail == 0)
		printf(GREEN "All passed!" RESET "\n");
	else
		printf(RED "%d failed" RESET " (showing first %d)\n",
			g_fail, MAX_REPORTS);
	return (g_fail != 0);
}
*/
