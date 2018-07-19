/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:28:24 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:28:24 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*cur_map;
	t_list	*cur;

	if (lst != NULL && f != NULL)
	{
		cur = lst;
		map = f(cur);
		cur_map = map;
		cur = cur->next;
		while (cur != NULL)
		{
			cur_map->next = f(cur);
			cur_map = cur_map->next;
			cur = cur->next;
		}
		cur_map->next = NULL;
		return (map);
	}
	return (NULL);
}
