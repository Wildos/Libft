/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:26:02 by tfernand          #+#    #+#             */
/*   Updated: 2018/07/19 12:51:21 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		res;
	int		pos;
	int		signe;

	pos = 0;
	signe = 1;
	res = 0;
	while (str[pos] == ' ' || str[pos] == '\t' || str[pos] == '\n'
		   || str[pos] == '\v' || str[pos] == '\f' || str[pos] == '\r')
		pos++;
	if (str[pos] == '-')
	{
		signe = -1;
		pos++;
	}
	else if (str[pos] == '+')
		pos++;
	while (str[pos] <= '9' && str[pos] >= '0')
	{
		res = res * 10 + (str[pos] - '0');
		pos++;
	}
	return (res * signe);
}
