/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent_to_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:30:40 by tfernand          #+#    #+#             */
/*   Updated: 2018/06/04 14:54:00 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pourcent_to_buffer(t_flags_ft_printf *flags, t_buff *buffer)
{
	return (ft_apply_width_and_precision(flags, "", "%", buffer));
}
