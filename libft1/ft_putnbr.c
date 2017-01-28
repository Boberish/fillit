/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:42:33 by mchen             #+#    #+#             */
/*   Updated: 2016/12/01 22:32:33 by mchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	if (n < 10 && n > -10)
		ft_putchar(n * sign + '0');
	else
	{
		ft_putnbr(n / 10 * sign);
		ft_putnbr(n % 10 * sign);
	}
}
