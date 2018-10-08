/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:35:46 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:35:46 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*ptr_s;
	char			*ptr;
	unsigned int	start;

	if (s == NULL)
		return (NULL);
	ptr_s = (char *)s;
	while (ft_iswhite(*ptr_s) && *ptr_s != '\0')
		ptr_s++;
	if (*ptr_s == '\0')
		return (ft_strnew(0));
	ptr = ptr_s;
	while (*ptr != '\0')
		ptr++;
	ptr--;
	while (ft_iswhite(*ptr))
		ptr--;
	ptr++;
	start = (unsigned int)(ptr_s - (char *)s);
	return (ft_strsub(s, start, (size_t)(ptr - ptr_s)));
}
