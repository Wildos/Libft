/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:35:38 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:35:38 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*m;

	if (s == NULL)
		return (NULL);
	m = ft_strnew(len);
	if (m == NULL)
		return (NULL);
	ft_strncpy(m, &s[start], len);
	return (m);
}
