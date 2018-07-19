/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:33:01 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:33:01 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(m = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	if (!(m = ft_strcat(m, s1)))
		return (NULL);
	if (!(m = ft_strcat(m, s2)))
		return (NULL);
	return (m);
}
