/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:33:36 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:33:37 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*m;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	m = ft_strnew(ft_strlen(s));
	if (m == NULL)
		return (NULL);
	ptr = m;
	while (*s != '\0')
	{
		*ptr = f(*s);
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (m);
}
