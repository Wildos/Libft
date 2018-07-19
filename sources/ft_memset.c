/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:29:48 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:29:49 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	val;
	size_t			i;
	unsigned char	*tab;

	val = (unsigned char)c;
	i = 0;
	tab = (unsigned char *)b;
	while (i < len)
	{
		tab[i] = val;
		i++;
	}
	return (b);
}
