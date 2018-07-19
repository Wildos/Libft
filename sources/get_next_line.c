/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:41:40 by tfernand          #+#    #+#             */
/*   Updated: 2018/07/19 11:43:09 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_find(char *str, char c)
{
	int		res;

	res = 0;
	while (str[res] != '\0' && str[res] != c)
		res++;
	return (res);
}

int		ft_strjoinf(char **line, char *buff, int *vld)
{
	char	*tmp;
	int		i;
	int		j;

	if (line == NULL || buff == NULL)
		return (-1);
	tmp = *line;
	*vld = 1;
	j = ft_find(buff, '\n');
	i = ft_strlen(*line) + j;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	ft_strcpy(*line, tmp);
	ft_strlcat(*line, buff, (i + 1));
	i = (buff[j] == '\n') ? 1 : 0;
	ft_strncpy(buff, (buff + j + i), BUFF_SIZE);
	free(tmp);
	if (*buff == '\0' && i == 0)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_data_buff	buff = {-1, {'\0'}};
	int					ret;
	int					vld;

	if (line == NULL || fd < 0 || fd == (int)stderr || fd == (int)stdout)
		return (-1);
	if (fd != buff.fd)
		ft_bzero(buff.data, BUFF_SIZE);
	if (!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	buff.fd = fd;
	**line = '\0';
	ret = 1;
	vld = 0;
	if (*(buff.data) == '\0')
		ret = read(fd, buff.data, BUFF_SIZE);
	while (ret > 0 && (ret = ft_strjoinf(line, buff.data, &vld)))
		ret = read(fd, buff.data, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	return (vld);
}
