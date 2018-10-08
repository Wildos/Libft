/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:35:30 by tfernand          #+#    #+#             */
/*   Updated: 2018/10/08 15:02:35 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			i = 1;
			while (haystack[i] != '\0' && needle[i] != '\0'
					&& haystack[i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
