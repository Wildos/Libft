/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:17:45 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 15:01:25 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_apply_width_unicode(t_flags_ft_printf *flags, int length,
	t_buff *buffer)
{
	int		i;

	i = 0;
	while (flags->width - i > length)
	{
		ft_add_char_to_buffer(' ', buffer);
		i++;
	}
	return (i);
}

static int	ft_print_unicode_string(wint_t *str_src, int length,
	t_buff *buffer)
{
	int		i;
	char	tab[5];
	int		len;
	int		char_writen;

	i = 0;
	char_writen = 0;
	len = 0;
	while (char_writen < length)
	{
		ft_bzero(tab, sizeof(tab));
		ft_get_unicode_char(tab, *(str_src));
		len = ft_strlen(tab);
		if (len == 0)
			return (-1);
		ft_add_area_to_buffer(tab, len, buffer);
		i += len;
		str_src++;
		char_writen++;
	}
	return (i);
}

static int	ft_unicode_string_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer)
{
	int				size;
	wint_t			*str;
	int				len;
	int				size_tmp;
	const wint_t	str_null[] = L"(null)";

	size = 0;
	len = 0;
	str = va_arg(*al, wint_t*);
	if (str == NULL)
		str = (wint_t*)str_null;
	while (str[len])
		len++;
	if (!(flags->flag & FLAG_M))
		size += ft_apply_width_unicode(flags, (flags->precision > len ||
			flags->precision == -1) ? len : flags->precision, buffer);
	size_tmp = ft_print_unicode_string(str, (flags->precision > len ||
		flags->precision == -1) ? len : flags->precision, buffer);
	if (size_tmp == -1)
		return (-1);
	size += size_tmp;
	if (flags->flag & FLAG_M)
		size += ft_apply_width_unicode(flags, (flags->precision > len ||
			flags->precision == -1) ? len : flags->precision, buffer);
	return (size);
}

int			ft_string_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer)
{
	int			i;
	char		*str;
	int			len;
	const char	str_null[] = "(null)";

	if (flags->length == 'l' || flags->type & TYPE_S)
		return (ft_unicode_string_to_buffer(flags, al, buffer));
	else
	{
		str = va_arg(*al, char*);
		if (str == NULL)
			str = (char *)str_null;
		i = 0;
		len = ft_strlen(str);
		if (!(flags->flag & FLAG_M))
			i += ft_apply_width_unicode(flags, (flags->precision > len ||
				flags->precision == -1) ? len : flags->precision, buffer);
		i += ft_add_area_to_buffer(str, (flags->precision > len ||
			flags->precision == -1) ? len : flags->precision, buffer);
		if (flags->flag & FLAG_M)
			i += ft_apply_width_unicode(flags, (flags->precision > len ||
				flags->precision == -1) ? len : flags->precision, buffer);
	}
	return (i);
}
