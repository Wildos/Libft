/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:39:14 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:55:42 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

static int	ft_add_plain_area(const char *restrict format,
	int *i, t_buff *buffer)
{
	int		base;

	base = 0;
	while (format[*i + base] && format[*i + base] != '%')
		ft_add_char_to_buffer(format[*i + base++], buffer);
	*i += base;
	return (base);
}

static int	ft_populate_flags(const char *restrict format,
	t_flags_ft_printf *flags)
{
	int		i;

	i = 0;
	if (format[i] && ft_is_flag(format[i]))
		ft_populate_flags_flags(format, &i, &(flags->flag));
	flags->width = -1;
	if (format[i] && ft_isdigit(format[i]))
	{
		flags->width = ft_get_number(format, &i);
	}
	flags->precision = -1;
	if (format[i] && format[i] == '.')
	{
		i++;
		flags->precision = ft_get_number(format, &i);
	}
	if (format[i] && ft_is_length_flag(format[i]))
		flags->length = ft_get_length_flag(format, &i);
	if (format[i] && ft_is_type_flag(format[i]))
		ft_populate_flags_type(format[i++], &(flags->type));
	return (i);
}

static int	ft_add_formated_area(const char *restrict format,
	int *i, va_list *al, t_buff *buffer)
{
	int					size;
	t_flags_ft_printf	flags;
	int					size_tmp;

	size = 0;
	size_tmp = 0;
	if (format[*i] == '\0')
		return (0);
	*i += 1;
	ft_bzero(&flags, sizeof(flags));
	*i += ft_populate_flags(&format[*i], &flags);
	size_tmp = ft_value_from_format(&flags, al, buffer);
	if (size_tmp == -1)
		return (-1);
	size += size_tmp;
	return (size);
}

int			ft_printf(const char *restrict format, ...)
{
	int		size;
	va_list	al;
	int		i;
	t_buff	buffer;
	int		size_tmp;

	size_tmp = 0;
	size = 0;
	if (format == NULL)
		return (-1);
	va_start(al, format);
	i = 0;
	ft_bzero(&buffer, sizeof(buffer));
	while (format[i])
	{
		size += ft_add_plain_area(format, &i, &buffer);
		size_tmp = ft_add_formated_area(format, &i, &al, &buffer);
		if (size_tmp == -1)
			return (-1);
		size += size_tmp;
	}
	write(1, buffer.buff, buffer.buff_size);
	va_end(al);
	return (size);
}
