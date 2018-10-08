/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:34:59 by tfernand          #+#    #+#             */
/*   Updated: 2018/10/08 15:02:46 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
		{
			i = 1;
			len--;
			while (haystack[i] != '\0' && len > 0 && needle[i] != '\0'
					&& haystack[i] == needle[i])
			{
				len--;
				i++;
			}
			if (needle[i] == '\0')
				return ((char *)haystack);
			len += i;
		}
		len--;
		haystack++;
	}
	return (NULL);
}
