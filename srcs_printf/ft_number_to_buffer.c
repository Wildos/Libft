/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_to_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:24:38 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 15:00:15 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_number_size(long long number, long long base)
{
	int res;

	res = 0;
	while (number >= base || number <= -base)
	{
		number /= base;
		res++;
	}
	res++;
	return (res);
}

int			ft_number_to_buffer(t_flags_ft_printf *flags, long long number,
		long long base, t_buff *buffer)
{
	char		buff_tmp[66];
	const char	base_char[] = "0123456789abcdef";
	int			i;
	char		prefix[3];

	ft_bzero(buff_tmp, sizeof(buff_tmp));
	ft_bzero(prefix, 3);
	i = ft_get_number_size(number, base);
	if (number < 0)
		prefix[0] = '-';
	else if (flags->flag & FLAG_P)
		prefix[0] = '+';
	else if (flags->flag & FLAG_S)
		prefix[0] = ' ';
	i--;
	while (number >= base || number <= -base)
	{
		buff_tmp[i--] = base_char[(number > 0 ? number % base :
				-(number % base))];
		number /= base;
	}
	buff_tmp[i] = base_char[(number > 0 ? number % base :
		-(number % base))];
	return (ft_apply_width_and_precision(flags, prefix,
		buff_tmp, buffer));
}

int			ft_get_unumber_size(unsigned long long number,
		unsigned long long base)
{
	int res;

	res = 0;
	while (number >= base)
	{
		number /= base;
		res++;
	}
	res++;
	return (res);
}

static void	ft_fill_prefix(t_flags_ft_printf *flags, unsigned long long number,
	char *prefix)
{
	ft_bzero(prefix, 3);
	if (flags->type & TYPE_PP || (flags->flag & FLAG_D && number != 0
		&& flags->type & (TYPE_XX | TYPE_X)))
	{
		prefix[0] = '0';
		prefix[1] = (flags->type & (TYPE_XX | TYPE_PP)) ? 'x' : 'X';
	}
}

int			ft_unumber_to_buffer(t_flags_ft_printf *flags,
		unsigned long long number, unsigned long long base, t_buff *buffer)
{
	char		buff_tmp[65];
	const char	base_char[] = "0123456789abcdef";
	int			i;
	char		prefix[3];

	ft_bzero(buff_tmp, sizeof(buff_tmp));
	i = ft_get_unumber_size(number, base);
	if (flags->flag & FLAG_D && flags->type & (TYPE_OO | TYPE_O) &&
		number != 0)
		buff_tmp[0] = '0';
	else
		i--;
	ft_fill_prefix(flags, number, prefix);
	while (number >= base && i > 0)
	{
		buff_tmp[i] = base_char[number % base];
		if (flags->type & TYPE_X && buff_tmp[i] >= 'a' && buff_tmp[i] <= 'z')
			buff_tmp[i] -= 32;
		number /= base;
		i--;
	}
	buff_tmp[i] = base_char[number % base];
	if (flags->type & TYPE_X && buff_tmp[i] >= 'a' && buff_tmp[i] <= 'z')
		buff_tmp[i] -= 32;
	return (ft_apply_width_and_precision(flags, prefix, buff_tmp, buffer));
}
