/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:30:52 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:30:52 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int res;

	res = n;
	if (n < 0)
	{
		res = -res;
		ft_putchar_fd('-', fd);
	}
	if (res >= 10)
		ft_putnbr_fd(res / 10, fd);
	ft_putchar_fd((char)(res % 10 + 48), fd);
}
