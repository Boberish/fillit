/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:04:27 by mchen             #+#    #+#             */
/*   Updated: 2016/12/06 11:05:09 by mchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *d;

	d = s1;
	while (*d)
		d++;
	while (n-- && *s2)
		*d++ = *s2++;
	*d = 0;
	return (s1);
}