/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:51:16 by mchen             #+#    #+#             */
/*   Updated: 2016/12/17 00:07:29 by mchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	map_init(int size)
{
	t_map	map;
	char	*temp;
	int		x;
	int		y;

	map.size = size;
	if (!(map.map = malloc(sizeof(*(map.map)) * ((size + 1) * size + 1))))
		return (map);
	temp = map.map;
	y = 0;
	while (y++ < size)
	{
		x = 0;
		while (x++ < size)
			*temp++ = '.';
		*temp++ = '\n';
	}
	*temp = 0;
	return (map);
}

int		piece_fits(t_map map, int i, t_tetro *tetros)
{
	int j;

	j = 0;
	while (tetros->tetro[j] && map.map[i])
	{
		if (map.map[i] != '.' && tetros->tetro[j] != '.')
			return (0);
		j++;
		i++;
		if (tetros->tetro[j] == '\n')
		{
			j++;
			i += map.size + 1 - tetros->width;
		}
	}
	return (1);
}

t_map	place_piece(t_map map, int i, t_tetro *tetros, char action)
{
	int j;

	j = 0;
	while (tetros->tetro[j])
	{
		if (tetros->tetro[j] != '.' && action == 'a')
			map.map[i] = tetros->tetro[j];
		else if (tetros->tetro[j] != '.' && action == 'r')
			map.map[i] = '.';
		j++;
		i++;
		if (tetros->tetro[j] == '\n')
		{
			j++;
			i += map.size + 1 - tetros->width;
		}
	}
	return (map);
}
