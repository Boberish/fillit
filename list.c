/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:51:16 by mchen             #+#    #+#             */
/*   Updated: 2016/12/17 00:09:19 by mchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetro	*new_tetro(char *t, char c)
{
	t_tetro	*tetro;

	if ((tetro = malloc(sizeof(*tetro))))
	{
		if (!valid_tetro(t))
			return (NULL);
		init_tetro(&tetro, t, c);
	}
	return (tetro);
}

int		list_tetros_helper(t_tetro **start, t_tetro **curr, char *buf,
		char *letter)
{
	if (!*start)
	{
		if (!(*start = new_tetro(buf, (*letter)++)))
			return (1);
		*curr = *start;
	}
	else
	{
		if (!((*curr)->next = new_tetro(buf, (*letter)++)))
			return (1);
		*curr = (*curr)->next;
	}
	return (0);
}

t_tetro	*list_tetros(int fd, int *t_count)
{
	t_tetro	*start;
	t_tetro	*curr;
	char	buf[21];
	int		read_len;
	char	letter;

	start = NULL;
	letter = 'A';
	while (fd != -1 && (read_len = read(fd, buf, 20)))
	{
		buf[read_len] = 0;
		if (list_tetros_helper(&start, &curr, buf, &letter))
			return (NULL);
		if (read(fd, buf, 1))
			if (*buf != '\n')
				return (NULL);
		*t_count = *t_count + 1;
	}
	if (*buf == '\n')
		return (NULL);
	return (start);
}

void	free_list(t_tetro **tetros)
{
	t_tetro *temp;
	t_tetro *temp2;

	if (!tetros)
		return ;
	temp = *tetros;
	while (temp)
	{
		free(temp->tetro);
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*tetros = NULL;
}
