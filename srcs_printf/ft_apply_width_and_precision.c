/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_and_precision.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:52:51 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 15:00:51 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_with_minus(t_flags_ft_printf *flags, const char *prefix,
	const char *string, t_buff *buffer)
{
	int		i;
	int		size;

	i = 0;
	size = (flags->precision > (int)ft_strlen(string)) ? flags->precision +
		ft_strlen(prefix) : ft_strlen(string) + ft_strlen(prefix);
	if ((!(*string) && flags->type & (TYPE_CC | TYPE_C)) || (flags->width > 1
		&& flags->type & TYPE_P))
		size = 1;
	i += ft_add_area_to_buffer(prefix, ft_strlen(prefix), buffer);
	if (flags->precision > (int)ft_strlen(string) && !(flags->type & TYPE_P))
		i += ft_add_whitespaces('0', flags->precision - ft_strlen(string),
			buffer);
	if (!(*string) && flags->type & (TYPE_CC | TYPE_C))
		i += ft_add_area_to_buffer(string, 1, buffer);
	else
		i += ft_add_area_to_buffer(string, ft_strlen(string), buffer);
	if (flags->width > size)
		i += ft_add_whitespaces(' ', flags->width - size, buffer);
	return (i);
}

static int	ft_alter_size(t_flags_ft_printf *flags, int size,
	const char *string)
{
	if (flags->width > 0 && flags->precision == 0 && *string == '0'
		&& ft_strlen(string) == 1)
		size = 0;
	if ((!(*string) && flags->type & (TYPE_CC | TYPE_C)) ||
		(flags->width > 1 && flags->type & TYPE_P))
		size = 1;
	return (size);
}

static int	ft_print_no_minus(t_flags_ft_printf *flags, const char *prefix,
	const char *string, t_buff *buffer)
{
	int		i;
	int		fl;
	int		size;

	fl = flags->flag;
	i = 0;
	size = (flags->precision > (int)ft_strlen(string)) ? flags->precision +
		ft_strlen(prefix) : ft_strlen(string) + ft_strlen(prefix);
	size = ft_alter_size(flags, size, string);
	if (!(fl & FLAG_Z && flags->precision == -1) && flags->width > size)
		i += ft_add_whitespaces(' ', flags->width - size, buffer);
	i += ft_add_area_to_buffer(prefix, ft_strlen(prefix), buffer);
	if (fl & FLAG_Z && flags->precision == -1 && flags->width > size)
		i += ft_add_whitespaces('0', flags->width - size, buffer);
	if (flags->precision > (int)ft_strlen(string) && !(flags->type & TYPE_P))
		i += ft_add_whitespaces('0', flags->precision - ft_strlen(string),
		buffer);
	if (!(*string) && flags->type & (TYPE_CC | TYPE_C))
		i += ft_add_area_to_buffer(string, 1, buffer);
	else if (size != 0 && !(flags->precision == 0 && *string == '0' &&
		!(fl & FLAG_D && flags->type & (TYPE_OO | TYPE_O))))
		i += ft_add_area_to_buffer(string, ft_strlen(string), buffer);
	return (i);
}

int			ft_apply_width_and_precision(t_flags_ft_printf *flags,
	const char *prefix, const char *string, t_buff *buffer)
{
	int		fl;

	fl = flags->flag;
	if (fl & FLAG_M)
		return (ft_print_with_minus(flags, prefix, string, buffer));
	return (ft_print_no_minus(flags, prefix, string, buffer));
}
