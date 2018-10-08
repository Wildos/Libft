/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_recuperation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 08:35:30 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:23:37 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_prst(const char c, char *src)
{
	while (*src)
	{
		if (*src == c)
			return (1);
		src++;
	}
	return (0);
}

void		ft_populate_flags_type(const char format, int16_t *dst)
{
	if (format == 's' || format == 'S')
		*dst |= (format == 's') ? TYPE_SS : TYPE_S;
	if (format == 'x' || format == 'X')
		*dst |= (format == 'x') ? TYPE_XX : TYPE_X;
	if (format == 'p')
		*dst |= TYPE_PP;
	if (format == '%')
		*dst |= TYPE_P;
	if (format == 'o' || format == 'O')
		*dst |= (format == 'o') ? TYPE_OO : TYPE_O;
	if (format == 'u' || format == 'U')
		*dst |= (format == 'u') ? TYPE_UU : TYPE_U;
	if (format == 'c' || format == 'C')
		*dst |= (format == 'c') ? TYPE_CC : TYPE_C;
	if (format == 'i' || format == 'd' || format == 'D')
		*dst |= (format == 'D') ? TYPE_D : TYPE_DD;
	if (format == 'b')
		*dst |= TYPE_B;
}

void		ft_populate_flags_flags(const char *restrict format,
	int *i, int8_t *dst)
{
	while (ft_is_flag(format[*i]))
	{
		if (format[*i] == '-')
			*dst |= FLAG_M;
		if (format[*i] == '+')
			*dst |= FLAG_P;
		if (format[*i] == '0')
			*dst |= FLAG_Z;
		if (format[*i] == ' ')
			*dst |= FLAG_S;
		if (format[*i] == '#')
			*dst |= FLAG_D;
		*i = *i + 1;
	}
}

int			ft_get_number(const char *restrict format, int *i)
{
	int		res;
	int		signe;

	res = 0;
	if (format[*i] == '-')
	{
		signe = -1;
		*i = *i + 1;
	}
	else
	{
		if (format[*i] == '+')
			*i = *i + 1;
		signe = 1;
	}
	if (!ft_isdigit(format[*i]))
		return (0);
	while (ft_isdigit(format[*i]))
	{
		res *= 10;
		res += format[*i] - '0';
		*i = *i + 1;
	}
	return (res);
}

char		ft_get_length_flag(const char *restrict format, int *i)
{
	if (ft_is_length_flag(format[*i]))
	{
		if (format[*i + 1] == format[*i] && (format[*i] == 'h'
			|| format[*i] == 'l'))
		{
			*i += 2;
			return (format[*i - 1] - 32);
		}
		*i = *i + 1;
	}
	return (format[*i - 1]);
}
