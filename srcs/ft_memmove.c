/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:29:35 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:29:38 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tab_in;
	unsigned char	*tab_out;
	size_t			i;

	tab_out = (unsigned char*)dst;
	tab_in = (unsigned char*)src;
	i = 0;
	while (i < len)
	{
		if (tab_out > tab_in)
			tab_out[len - 1 - i] = tab_in[len - 1 - i];
		else
			tab_out[i] = tab_in[i];
		i++;
	}
	return (dst);
}
