/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_char_to_buffer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:33:55 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:56:12 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_single_char_to_buffer(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer)
{
	char	c[2];

	ft_bzero(c, sizeof(c));
	if (flags->length == 'l' || flags->type & TYPE_C)
		return (ft_unicode_char_to_buffer(flags, al, buffer));
	c[0] = (char)va_arg(*al, int);
	if (c[0] == 0)
	{
		return (ft_apply_width_and_precision(flags, "", "\0", buffer));
	}
	return (ft_apply_width_and_precision(flags, "", c, buffer));
}
