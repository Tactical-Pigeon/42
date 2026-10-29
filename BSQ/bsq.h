/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelorza <gelorza@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:56:01 by gelorza           #+#    #+#             */
/*   Updated: 2026/10/28 22:38:11 by gelorza          ###   ########.fr       */
/*   Updated: 2026/10/27 19:50:57 by gelorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		len_line(char *buf, int *pos);
int		len_rows(char *body);
int		ft_cabezera(char *buf, char *cells, int *pos);
int		ft_valid_cells(char *cells);
int		ft_valid_map(char **map, char *cells, int row, int col);
char	**create_map(int row, int col);
void	fill_map(char *body, char **map, int row, int col);
void	print_map(char **map, int row, int col);
void	ft_find(char **map, char *cells, int maxy, int length);
char	*ft_grow(char *old, int size, int cap);
char	*ft_read_all(int fd);
void	free_map(char **map, int row);

#endif
