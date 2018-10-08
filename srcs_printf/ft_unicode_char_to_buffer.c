/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_char_to_buffer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:23:02 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 15:10:27 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_transfert_byte(char *dst, char src)
{
	int		i;

	i = 0;
	while (src && i < 8)
	{
		*dst |= (src & 1) << i;
		src >>= 1;
		i++;
	}
}

static void	ft_transfert_wint_t_to_char_tab(wint_t src, char *dst,
	int length)
{
	int		i;

	i = length - 1;
	while (i >= 0)
	{
		if (i == 0)
		{
			if (length == 1)
				ft_transfert_byte(&dst[i], (char)src & UCODE_DEFAULT);
			else if (length == 2)
				ft_transfert_byte(&dst[i], ((char)src & UCODE_ELEVEN)
				| UCODE_BASE_ELEVEN);
			else if (length == 3)
				ft_transfert_byte(&dst[i], ((char)src & UCODE_SIXTEEN)
				| UCODE_BASE_SIXTEEN);
			else if (length == 4)
				ft_transfert_byte(&dst[i], ((char)src & UCODE_TWENTY_ONE)
				| UCODE_BASE_TWENTY_ONE);
			break ;
		}
		ft_transfert_byte(&dst[i], ((char)src & UCODE_NEXT)
			| UCODE_BASE_NEXT);
		src >>= 6;
		i--;
	}
}

static int	ft_get_char_size(wint_t c)
{
	int i;

	i = 0;
	while (c && c > 0)
	{
		c >>= 1;
		i++;
	}
	return (i);
}

int			ft_get_unicode_char(char *dst, wint_t src)
{
	int size;

	size = ft_get_char_size(src);
	if (size <= 0 || src < 0 || (src > 255 && size <= 7) ||
		(src >= 0xd800 && src <= 0xdfff) || src > 0x10ffff)
		return (1);
	else if (size <= 7)
		ft_transfert_wint_t_to_char_tab(src, dst, 1);
	else if (size <= 11)
		ft_transfert_wint_t_to_char_tab(src, dst, 2);
	else if (size <= 16)
		ft_transfert_wint_t_to_char_tab(src, dst, 3);
	else if (size <= 21)
		ft_transfert_wint_t_to_char_tab(src, dst, 4);
	else
		return (1);
	return (0);
}

int			ft_unicode_char_to_buffer(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer)
{
	wint_t	c;
	char	c_tab[5];

	ft_bzero(c_tab, sizeof(c_tab));
	c = va_arg(*al, wint_t);
	if (c == 0)
		return (ft_apply_width_and_precision(flags, "", c_tab, buffer));
	if (ft_get_unicode_char(c_tab, c))
		return (-1);
	if (ft_strlen(c_tab) == 0)
		return (-1);
	return (ft_apply_width_and_precision(flags, "", c_tab, buffer));
}
