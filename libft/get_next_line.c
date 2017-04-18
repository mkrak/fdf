/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:47:15 by mkrakows          #+#    #+#             */
/*   Updated: 2017/03/10 17:17:33 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_mycpy(char **dst, char *src)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (src[i] != '\n')
		i++;
	CHECKMALLOC((tmp = (char*)malloc(sizeof(char) * i + 1)));
	i = -1;
	while (src[++i] != '\n')
		tmp[i] = src[i];
	tmp[i] = '\0';
	*dst = tmp;
	i += 1;
	while (src[i] != '\0')
	{
		src[j] = src[i];
		i++;
		j++;
	}
	src[j] = '\0';
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock[NBFD];
	char		buf[BUFF_SIZE + 1];
	int			r;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) || fd > NBFD)
		return (-1);
	if (stock[fd] == NULL)
		CHECKMALLOC((stock[fd] = malloc(1)));
	if (stock[fd] && (ft_strchr(stock[fd], '\n') != 0))
		return (ft_mycpy(line, stock[fd]));
	while ((r = read(fd, buf, BUFF_SIZE)))
	{
		buf[r] = '\0';
		stock[fd] = ft_joinfree(stock[fd], buf, &stock[fd]);
		if (ft_strchr(stock[fd], '\n') != 0)
			return (ft_mycpy(line, stock[fd]));
	}
	if (stock[fd][0] != '\0')
	{
		CHECKMALLOC((*line = malloc(ft_strlen(stock[fd]))));
		*line = ft_strcpy(*line, stock[fd]);
		bzero(stock[fd], ft_strlen(stock[fd]));
		return (1);
	}
	return (0);
}
