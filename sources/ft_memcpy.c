/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:29:18 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:29:18 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tab_out;
	char	*tab_in;
	size_t	i;

	tab_out = (char *)dst;
	tab_in = (char *)src;
	i = 0;
	while (i < n)
	{
		tab_out[i] = tab_in[i];
		i++;
	}
	return (dst);
}
