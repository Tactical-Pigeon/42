/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 21:38:07 by nahardan          #+#    #+#             */
/*   Updated: 2026/10/25 22:46:36 by nahardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H

# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/* main / check */
int		ft_validate_input(char *num);
int		ft_controller(char *num, char *path);

/* number to words */
int		ft_setnum(char *num, char **dict, char **result);
int		ft_scale(int th, char **dict, char **res);
char	ft_group_digit(const char *g, int n, int pos);
int		ft_is_zero(const char *g, int n);
int		ft_hundreds(const char *g, int n, char **dict, char **res);
int		ft_tens_units(const char *g, int n, char **dict, char **res);
int		ft_group(const char *g, int n, char **dict, char **res);
void	ft_fill_join(char *joined, const char *old, const char *word);
int		ft_append_word(char **result, const char *word);
int		ft_add_key(char **dict, const char *key, char **result);

/* The array contains key, value, key, value, ..., NULL. */
char	**ft_parse_dict(const char *path);
char	*ft_dict_get(char **dict, const char *key);
void	ft_dict_free(char **dict);

/* Helpers shared between the dictionary source files. */
void	ft_clear_slots(char **dict, size_t slots);
char	**ft_create_dict(size_t count);
char	*ft_join_alloc(size_t length, size_t chunk_size);
char	*ft_dict_read(const char *path);
int		ft_dict_add(char **dict, size_t slot, char *line);
int		ft_dict_required(char **dict);
size_t	ft_dict_strlen(const char *str);
int		ft_dict_equal(const char *left, const char *right);
char	*ft_dict_dup(const char *str);
void	ft_dict_number_key(unsigned int number, char *key);
int		ft_is_pow100(const char *s);
int		ft_whole(const char *num, char **dict, char **result);
int		ft_walk(char *num, int th, char **dict, char **result);

#endif
