/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:30:45 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:30:45 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int res;

	res = n;
	if (n < 0)
	{
		ft_putchar('-');
		res = res * -1;
	}
	if (res >= 10)
		ft_putnbr(res / 10);
	ft_putchar((char)(res % 10 + 48));
}
