/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:48:13 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/03 23:00:02 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# include <stddef.h>

# include <stdint.h>

# include <wchar.h>

# include <stdlib.h>

# define BUFF_SIZE 1024

/*
** Unicode mask
*/
# define UCODE_DEFAULT 0x7f
# define UCODE_ELEVEN 0x1F
# define UCODE_SIXTEEN 0xF
# define UCODE_TWENTY_ONE 0x7
# define UCODE_NEXT 0x3F

# define UCODE_BASE_ELEVEN 0xC0
# define UCODE_BASE_SIXTEEN 0xE0
# define UCODE_BASE_TWENTY_ONE 0xF0
# define UCODE_BASE_NEXT 0x80

/*
** flag bit
** 0000 0001 : -
** 0000 0010 : +
** 0000 0100 : 0
** 0000 1000 : ' '
** 0001 0000 : #
*/
# define FLAG_M 1
# define FLAG_P 2
# define FLAG_Z 4
# define FLAG_S 8
# define FLAG_D 16

/*
** 0000 0000 0000 0001 : s
** 0000 0000 0000 0010 : S
** 0000 0000 0000 0100 : % identified as 'P'
** 0000 0000 0000 1000 : p
** 0000 0000 0001 0000 : x
** 0000 0000 0010 0000 : X
** 0000 0000 0100 0000 : o
** 0000 0000 1000 0000 : O
** 0000 0001 0000 0000 : u
** 0000 0010 0000 0000 : U
** 0000 0100 0000 0000 : i
** 0000 0100 0000 0000 : d
** 0000 1000 0000 0000 : D
** 0001 0000 0000 0000 : c
** 0010 0000 0000 0000 : C
** 0100 0000 0000 0000 : b
*/
# define TYPE_SS 1
# define TYPE_S 2
# define TYPE_P 4
# define TYPE_PP 8
# define TYPE_XX 16
# define TYPE_X 32
# define TYPE_OO 64
# define TYPE_O 128
# define TYPE_UU 256
# define TYPE_U 512
# define TYPE_DD 1024
# define TYPE_D 2048
# define TYPE_CC 4096
# define TYPE_C 8192
# define TYPE_B 16384

typedef struct	s_flags_ft_printf
{
	int8_t		flag;
	int			width;
	int			precision;
	char		length;
	int16_t		type;
}				t_flags_ft_printf;

typedef struct	s_buff
{
	char			buff[BUFF_SIZE];
	unsigned int	buff_size;
}				t_buff;

void			ft_add_char_to_buffer(const char c, t_buff *buffer);
int				ft_add_area_to_buffer(const char *format, int length,
	t_buff *buffer);
int				ft_add_whitespaces(const char c, int nb, t_buff *buffer);

int				ft_is_flag(const char c);
int				ft_is_length_flag(const char c);
int				ft_is_type_flag(const char c);

int				ft_is_prst(const char c, char *src);
void			ft_populate_flags_type(const char format, int16_t *dst);
void			ft_populate_flags_flags(const char *restrict format,
	int *i, int8_t *dst);
int				ft_get_number(const char *restrict format, int *i);
char			ft_get_length_flag(const char *restrict format, int *i);

int				ft_string_to_buffer(t_flags_ft_printf *flags, va_list *al,
	t_buff *buffer);

int				ft_get_unicode_char(char *dst, wint_t src);
int				ft_unicode_char_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_single_char_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_integer_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_unsigned_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_onumber_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_binary_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_xnumber_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_pointer_to_buffer(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_pourcent_to_buffer(t_flags_ft_printf *flags, t_buff *buffer);

int				ft_apply_width_and_precision(t_flags_ft_printf *flags,
	const char *prefix, const char *string, t_buff *buffer);

int				ft_get_number_size(long long number, long long base);
int				ft_number_to_buffer(t_flags_ft_printf *flags,
	long long number, long long base, t_buff *buffer);
int				ft_get_unumber_size(unsigned long long number,
	unsigned long long base);
int				ft_unumber_to_buffer(t_flags_ft_printf *flags,
	unsigned long long number, unsigned long long base, t_buff *buffer);

int				ft_value_from_format(t_flags_ft_printf *flags,
	va_list *al, t_buff *buffer);

int				ft_printf(const char *restrict format, ...);

#endif
