/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:34:07 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:34:07 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *ptr1;
	char *ptr2;

	ptr1 = s1;
	ptr2 = (char *)s2;
	while (*ptr1 != '\0')
	{
		ptr1++;
	}
	while (*ptr2 != '\0' && n > 0)
	{
		*ptr1 = *ptr2;
		n--;
		ptr1++;
		ptr2++;
	}
	*ptr1 = '\0';
	return (s1);
}
