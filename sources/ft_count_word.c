/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:26:17 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:26:18 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_count_word(char const *s, char c)
{
	int			nbr;

	if (s == NULL)
		return (0);
	nbr = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			nbr++;
			while (*(s + 1) != '\0' && *s != c)
				s++;
		}
		s++;
	}
	return (nbr);
}
