/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:46:04 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/19 17:26:31 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	size_t	len;
	size_t	i;

	map = NULL;
	if (s && f)
	{
		i = 0;
		len = ft_strlen(s);
		if ((map = (char*)malloc(sizeof(char) * (len + 1))) == 0)
			return (NULL);
		while (i < len)
		{
			map[i] = (*f)(i, s[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
