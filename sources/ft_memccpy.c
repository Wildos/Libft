/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:28:53 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:28:54 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab_out;
	unsigned char	*tab_in;

	tab_out = (unsigned char *)dst;
	tab_in = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tab_out[i] = tab_in[i];
		if (tab_in[i] == (unsigned char)c)
			return ((void *)&tab_out[i + 1]);
		i++;
	}
	return (NULL);
}
