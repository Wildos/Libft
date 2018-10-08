/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_to_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:10:22 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:32:38 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_integer_to_buffer(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer)
{
	if (flags->type & TYPE_D)
		return (ft_number_to_buffer(flags,
			(long long)va_arg(*al, long), 10, buffer));
	else if (flags->length == 'H')
		return (ft_number_to_buffer(flags,
			(long long)(char)va_arg(*al, int), 10, buffer));
	else if (flags->length == 'h')
		return (ft_number_to_buffer(flags,
			(long long)(short)va_arg(*al, int), 10, buffer));
	else if (flags->length == 'l')
		return (ft_number_to_buffer(flags,
			(long long)va_arg(*al, long), 10, buffer));
	else if (flags->length == 'L')
		return (ft_number_to_buffer(flags,
			(long long)va_arg(*al, long long), 10, buffer));
	else if (flags->length == 'j')
		return (ft_number_to_buffer(flags,
			(long long)va_arg(*al, intmax_t), 10, buffer));
	else if (flags->length == 'z')
		return (ft_number_to_buffer(flags,
			(long long)va_arg(*al, size_t), 10, buffer));
	else
		return (ft_number_to_buffer(flags,
	(long long)va_arg(*al, int), 10, buffer));
}
