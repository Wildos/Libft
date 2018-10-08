/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:33:54 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:33:54 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*m;
	char			*ptr;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	m = ft_strnew(ft_strlen(s));
	if (m == NULL)
		return (NULL);
	ptr = m;
	i = 0;
	while (*s != '\0')
	{
		*ptr = f(i, *s);
		ptr++;
		i++;
		s++;
	}
	*ptr = '\0';
	return (m);
}
