/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:27:29 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:27:29 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_int_len(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[0] = '-';
	if (n < 0)
		n = -n;
	len--;
	while (n >= 10)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	str[len] = n + '0';
	return (str);
}
