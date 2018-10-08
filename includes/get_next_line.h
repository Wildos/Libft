/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:59:33 by tfernand          #+#    #+#             */
/*   Updated: 2018/05/01 11:13:02 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 52
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

int				get_next_line(const int fd, char **line);

typedef struct	s_data_buff
{
	int					fd;
	char				data[BUFF_SIZE + 2];
}				t_data_buff;

#endif
