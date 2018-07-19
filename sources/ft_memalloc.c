/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:28:43 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:28:44 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*m;
	char	*ptr;

	m = malloc(size);
	if (m == NULL)
		return (NULL);
	ptr = (char *)m;
	while (size > 0)
	{
		*ptr = '\0';
		ptr++;
		size--;
	}
	return (m);
}
