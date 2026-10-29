/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 21:34:57 by nahardan          #+#    #+#             */
/*   Updated: 2026/10/25 21:35:13 by nahardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_controller(char *num, char *path)
{
	char	**dict;
	char	*result;
	int		ok;

	dict = ft_parse_dict(path);
	if (!dict)
		return (1);
	ok = ft_setnum(num, dict, &result);
	if (ok)
	{
		write(1, result, ft_dict_strlen(result));
		write(1, "\n", 1);
	}
	free(result);
	ft_dict_free(dict);
	if (!ok)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*num;
	char	*path;

	path = "numbers.dict";
	num = argv[argc - 1];
	if (argc == 3)
		path = argv[1];
	if ((argc != 2 && argc != 3) || !ft_validate_input(num))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (ft_controller(num, path))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}
