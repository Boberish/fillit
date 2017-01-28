/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:10:27 by mchen             #+#    #+#             */
/*   Updated: 2016/12/17 15:47:01 by mchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "../libft1/libft.h"

typedef struct		s_tetro
{
	unsigned int	height;
	unsigned int	width;
	char			*tetro;
	struct s_tetro	*next;
}					t_tetro;

typedef struct		s_map
{
	char			*map;
	unsigned int	size;
}					t_map;

t_tetro				*new_tetro(char *t, char c);
int					list_tetros_helper(t_tetro **start, t_tetro **curr,
					char *buf, char *letter);
t_tetro				*list_tetros(int fd, int *t_count);
void				free_list(t_tetro **tetros);
t_map				map_init(int size);
int					piece_fits(t_map map, int i, t_tetro *tetros);
t_map				place_piece(t_map map, int i, t_tetro *tetros, char action);
void				ft_putstr(char const *s);
int					ft_sqrt_ceil(unsigned int nb);
char				*ft_strnew(size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_chrrep(char *s, char c, char r);
int					valid_shape(char *tetro);
int					valid_tetro(char *tetro);
void				init_init_tetro(int *bound, char *t, int *j, int *i);
void				init_tetro(t_tetro **n_tetro, char *t, char c);
int					solve_fillit_2(t_map map, t_tetro *tetros);
t_map				solve_fillit(t_tetro *tetros, int t_count);

#endif
