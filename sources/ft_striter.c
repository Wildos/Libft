/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:32:46 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:32:46 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	char	*ptr;
	size_t	i;

	if (s != NULL && f != NULL)
	{
		ptr = s;
		i = 0;
		while (ptr[i] != '\0')
		{
			f(&ptr[i]);
			i++;
		}
	}
}
