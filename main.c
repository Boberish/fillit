/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:51:16 by mchen             #+#    #+#             */
/*   Updated: 2016/12/17 00:07:08 by mchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_fillit_2(t_map map, t_tetro *tetros)
{
	int i;

	if (!tetros)
		return (1);
	i = 1;
	while (tetros->height <= map.size - i / (map.size + 1))
	{
		while (tetros->width <= map.size + 1 - i % (map.size + 1) &&
				i % (map.size + 1) != 0)
		{
			if (piece_fits(map, i - 1, tetros))
			{
				if (solve_fillit_2(place_piece(map, i - 1, tetros, 'a'),
					tetros->next))
					return (1);
				else
					place_piece(map, i - 1, tetros, 'r');
			}
			i++;
		}
		i++;
	}
	return (0);
}

t_map	solve_fillit(t_tetro *tetros, int t_count)
{
	t_map	map;
	int		size;

	size = ft_sqrt_ceil(t_count * 4);
	map = map_init(size++);
	while (!solve_fillit_2(map, tetros))
	{
		free(map.map);
		map = map_init(size++);
	}
	return (map);
}

int		main(int ac, char **av)
{
	t_tetro	*tetros;
	t_map	map;
	int		t_count;

	if (ac != 2)
	{
		ft_putstr("fillit tetromino_file\n");
		return (1);
	}
	t_count = 0;
	if (!(tetros = list_tetros(open(av[1], O_RDONLY), &t_count)))
	{
		ft_putstr("error\n");
		return (2);
	}
	map = solve_fillit(tetros, t_count);
	ft_putstr(map.map);
	free(map.map);
	free_list(&tetros);
	return (0);
}
