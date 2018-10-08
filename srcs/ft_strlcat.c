/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:33:11 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:33:11 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ptr1;
	char	*ptr2;
	int		n;

	ptr1 = dst;
	n = 0;
	ptr2 = (char *)src;
	while (*ptr1 != '\0' && size > 0)
	{
		n++;
		size--;
		ptr1++;
	}
	if (size < 1)
		return (n + size + ft_strlen(src));
	while (*ptr2 != '\0' && size > 1)
	{
		*ptr1 = *ptr2;
		size--;
		ptr1++;
		ptr2++;
	}
	*ptr1 = '\0';
	return (n + ft_strlen(src));
}
