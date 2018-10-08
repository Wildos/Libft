/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_identification.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:40:40 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/03 22:38:11 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_flag(const char c)
{
	if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#')
		return (1);
	return (0);
}

int		ft_is_length_flag(const char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		ft_is_type_flag(const char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'i' || c == 'p'
		|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
		|| c == 'X' || c == 'c' || c == 'C' || c == '%' || c == 'b')
		return (1);
	return (0);
}
