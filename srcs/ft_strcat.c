/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:31:19 by tfernand          #+#    #+#             */
/*   Updated: 2018/04/11 17:31:22 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char *ptr1;
	char *ptr2;

	ptr1 = s1;
	ptr2 = (char *)s2;
	while (*ptr1 != '\0')
	{
		ptr1++;
	}
	while (*ptr2 != '\0')
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	*ptr1 = '\0';
	return (s1);
}