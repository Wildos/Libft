/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_to_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:16:19 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 15:12:02 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned_to_buffer(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer)
{
	if (flags->type & TYPE_U)
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long), 10, buffer));
	else if (flags->length == 'H')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)(unsigned char)va_arg(*al, unsigned), 10, buffer));
	else if (flags->length == 'h')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)(unsigned short)va_arg(*al, unsigned), 10, buffer));
	else if (flags->length == 'l')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long), 10, buffer));
	else if (flags->length == 'L')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long long), 10, buffer));
	else if (flags->length == 'j')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, uintmax_t), 10, buffer));
	else if (flags->length == 'z')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, ssize_t), 10, buffer));
	else
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned), 10, buffer));
}
