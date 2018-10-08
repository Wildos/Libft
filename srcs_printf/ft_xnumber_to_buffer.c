/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xnumber_to_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:00:42 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 15:14:23 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_xnumber_to_buffer(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer)
{
	char		length;

	length = flags->length;
	if (length == 'H')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)(unsigned char)va_arg(*al, unsigned), 16, buffer));
	else if (length == 'h')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)(unsigned short)va_arg(*al, unsigned), 16, buffer));
	else if (length == 'l')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long), 16, buffer));
	else if (length == 'L')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned long long), 16, buffer));
	else if (length == 'j')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, uintmax_t), 16, buffer));
	else if (length == 'z')
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, ssize_t), 16, buffer));
	else
		return (ft_unumber_to_buffer(flags,
		(unsigned long long)va_arg(*al, unsigned), 16, buffer));
}
