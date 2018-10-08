/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:35:00 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:12:40 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_binary_to_buffer(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer)
{
	char	length;

	length = flags->length;
	if (length == 'H')
		return (ft_unumber_to_buffer(flags,
	(unsigned long long)(unsigned char)va_arg(*al, unsigned), 2, buffer));
	else if (length == 'h')
		return (ft_unumber_to_buffer(flags,
	(unsigned long long)(unsigned short)va_arg(*al, unsigned), 2, buffer));
	else if (length == 'l')
		return (ft_unumber_to_buffer(flags,
	(unsigned long long)va_arg(*al, unsigned long), 2, buffer));
	else if (length == 'L')
		return (ft_unumber_to_buffer(flags,
	(unsigned long long)va_arg(*al, unsigned long long), 2, buffer));
	else if (length == 'j')
		return (ft_unumber_to_buffer(flags,
	(unsigned long long)va_arg(*al, uintmax_t), 2, buffer));
	else if (length == 'z')
		return (ft_unumber_to_buffer(flags,
	(unsigned long long)va_arg(*al, ssize_t), 2, buffer));
	else
		return (ft_unumber_to_buffer(flags,
	(unsigned long long)va_arg(*al, unsigned), 2, buffer));
}
