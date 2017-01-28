/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:51:16 by mchen             #+#    #+#             */
/*   Updated: 2016/12/17 00:07:16 by mchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_shape(char *tetro)
{
	int		pound_cnt;
	int		i;
	int		contact;

	pound_cnt = 0;
	contact = 0;
	i = -1;
	while (tetro[++i])
	{
		if (tetro[i] == '#')
		{
			if (i / 5 > 0)
				contact += tetro[i - 5] == '#' ? 1 : 0;
			if (i / 5 < 4)
				contact += tetro[i + 5] == '#' ? 1 : 0;
			if (i % 5 > 0)
				contact += tetro[i - 1] == '#' ? 1 : 0;
			if (i % 5 < 4)
				contact += tetro[i + 1] == '#' ? 1 : 0;
			pound_cnt++;
		}
	}
	if (pound_cnt == 4 && contact > 5)
		return (1);
	return (0);
}

int		valid_tetro(char *tetro)
{
	char	*s;
	char	*e;
	int		rows;

	rows = 1;
	s = tetro;
	e = s;
	while (rows++ < 5)
	{
		while (*e && *e != '\n')
		{
			if (*e != '.' && *e != '#')
				return (0);
			e++;
		}
		if (e - s != 4)
			return (0);
		s = ++e;
	}
	if (*s == 0)
		return (valid_shape(tetro));
	return (0);
}

void	init_init_tetro(int *bound, char *t, int *j, int *i)
{
	bound[0] = 4;
	bound[1] = 0;
	bound[2] = 4;
	bound[3] = 0;
	*i = 0;
	while (t[*i])
	{
		if (t[*i] == '#')
		{
			if (*i % 5 < bound[0])
				bound[0] = *i % 5;
			if (*i % 5 > bound[1])
				bound[1] = *i % 5;
			if (*i / 5 < bound[2])
				bound[2] = *i / 5;
			if (*i / 5 > bound[3])
				bound[3] = *i / 5;
		}
		(*i)++;
	}
	*i = 0;
	*j = bound[0] + bound[2] * 5;
}

void	init_tetro(t_tetro **n_tetro, char *t, char c)
{
	char	*tetro;
	int		bound[4];
	int		i;
	int		j;

	init_init_tetro(bound, t, &j, &i);
	while (i++ < j)
		t++;
	t = ft_chrrepl(t, '#', c);
	if (!(tetro = malloc(sizeof(*tetro) * ((bound[1] - bound[0] + 1) *
		(bound[3] - bound[2] + 1) + 1))))
		return ;
	*tetro = 0;
	i = 1;
	while (i++ <= bound[3] - bound[2] + 1)
	{
		tetro = ft_strncat(tetro, t, bound[1] - bound[0] + 1);
		tetro = ft_strncat(tetro, "\n", 1);
		t = t + 5;
	}
	(*n_tetro)->tetro = tetro;
	(*n_tetro)->height = bound[3] - bound[2] + 1;
	(*n_tetro)->width = bound[1] - bound[0] + 1;
	(*n_tetro)->next = NULL;
}
