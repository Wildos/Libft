/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:34:22 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:34:23 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (*src != '\0' && len > 0)
	{
		len--;
		*ptr = *src;
		ptr++;
		src++;
	}
	while (len > 0)
	{
		len--;
		*ptr = '\0';
		ptr++;
	}
	return (dst);
}
