/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:31:31 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:31:31 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char to_find;
	char *ptr;

	to_find = (char)c;
	ptr = (char *)s;
	while (*ptr != '\0' && *ptr != to_find)
	{
		ptr++;
	}
	if (*ptr == to_find)
		return (ptr);
	else
		return (NULL);
}
