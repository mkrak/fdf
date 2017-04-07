/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:43:22 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/19 16:44:52 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	i;
	size_t	j;

	res = 0;
	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
	{
		res++;
		i++;
	}
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (res < size)
		dst[i] = '\0';
	return (res + ft_strlen(src));
}
