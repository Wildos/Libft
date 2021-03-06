/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:26:10 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:26:11 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char	*tab;
	size_t	i;

	tab = (char *)s;
	i = 0;
	while (i < n)
	{
		tab[i] = '\0';
		i++;
	}
}
