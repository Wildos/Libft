/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_to_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 09:14:19 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 15:13:14 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_value_from_format(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer)
{
	if (flags->type & TYPE_SS || flags->type & TYPE_S)
		return (ft_string_to_buffer(flags, al, buffer));
	if (flags->type & TYPE_CC || flags->type & TYPE_C)
		return (ft_single_char_to_buffer(flags, al, buffer));
	if (flags->type & TYPE_DD || flags->type & TYPE_D)
		return (ft_integer_to_buffer(flags, al, buffer));
	if (flags->type & TYPE_UU || flags->type & TYPE_U)
		return (ft_unsigned_to_buffer(flags, al, buffer));
	if (flags->type & TYPE_OO || flags->type & TYPE_O)
		return (ft_onumber_to_buffer(flags, al, buffer));
	if (flags->type & TYPE_XX || flags->type & TYPE_X)
		return (ft_xnumber_to_buffer(flags, al, buffer));
	if (flags->type & TYPE_PP)
		return (ft_pointer_to_buffer(flags, al, buffer));
	if (flags->type & TYPE_P)
		return (ft_pourcent_to_buffer(flags, buffer));
	if (flags->type & TYPE_B)
		return (ft_binary_to_buffer(flags, al, buffer));
	return (0);
}
