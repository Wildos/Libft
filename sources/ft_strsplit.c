/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:35:19 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:35:20 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words_nbr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	words_nbr = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words_nbr + 1))))
		return (NULL);
	words_nbr = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != '\0' && s[i] != c)
				i++;
			tab[words_nbr++] = ft_strsub(s, 0, i);
			s += i;
		}
		else
			s++;
	}
	tab[words_nbr] = NULL;
	return (tab);
}
