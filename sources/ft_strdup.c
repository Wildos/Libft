/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:32:29 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:32:29 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*res;

	if (!(res = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	ptr = res;
	while (*s != '\0')
	{
		*ptr = *s;
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (res);
}
