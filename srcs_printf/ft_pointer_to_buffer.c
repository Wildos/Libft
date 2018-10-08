/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_to_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:23:08 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:53:27 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pointer_to_buffer(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer)
{
	return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long), 16, buffer));
}
