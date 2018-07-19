/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:35:08 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:35:10 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char to_find;
	char *ptr;
	char *res;

	to_find = (char)c;
	ptr = (char *)s;
	res = NULL;
	while (*ptr != '\0')
	{
		if (*ptr == to_find)
			res = ptr;
		ptr++;
	}
	if (*ptr == to_find)
		return (ptr);
	return (res);
}
