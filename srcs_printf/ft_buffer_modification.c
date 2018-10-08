/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_modification.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 08:59:36 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:17:39 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void		ft_add_char_to_buffer(const char c, t_buff *buffer)
{
	buffer->buff[buffer->buff_size] = c;
	buffer->buff_size++;
	if (buffer->buff_size == BUFF_SIZE)
	{
		write(1, buffer->buff, BUFF_SIZE);
		ft_bzero(buffer->buff, BUFF_SIZE);
		buffer->buff_size = 0;
	}
}

int			ft_add_whitespaces(const char c, int nb, t_buff *buffer)
{
	int		i;

	i = nb;
	while (nb-- > 0)
		ft_add_char_to_buffer(c, buffer);
	return (i);
}

int			ft_add_area_to_buffer(const char *format, int length,
	t_buff *buffer)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (length > 0)
	{
		ft_add_char_to_buffer(format[i], buffer);
		length--;
		i++;
		res++;
	}
	return (res);
}
