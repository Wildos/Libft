/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:27:57 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:27:57 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*to_del;

	if (alst != NULL && *alst != NULL)
	{
		next = *alst;
		while (next != NULL)
		{
			to_del = next;
			next = next->next;
			ft_lstdelone(&to_del, del);
		}
		*alst = NULL;
	}
}
