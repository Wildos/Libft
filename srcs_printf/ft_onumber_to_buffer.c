/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ointeger_to_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:45:01 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:52:10 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_onumber_to_buffer(t_flags_ft_printf *flags, va_list *al,
		t_buff *buffer)
{
	if (flags->type & TYPE_O)
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long), 8, buffer));
	else if (flags->length == 'H')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)(unsigned char)va_arg(*al, unsigned), 8, buffer));
	else if (flags->length == 'h')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)(unsigned short)va_arg(*al, unsigned), 8, buffer));
	else if (flags->length == 'l')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long), 8, buffer));
	else if (flags->length == 'L')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long long), 8, buffer));
	else if (flags->length == 'j')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, uintmax_t), 8, buffer));
	else if (flags->length == 'z')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, size_t), 8, buffer));
	else
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned), 8, buffer));
}
