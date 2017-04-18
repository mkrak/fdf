/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:18:49 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/07 15:57:56 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int size;

	size = ft_strlen(s);
	while (s[size] != (char)c && size >= 0)
		size--;
	if (s[size] == (char)c)
		return ((char *)s + size);
	return (NULL);
}
