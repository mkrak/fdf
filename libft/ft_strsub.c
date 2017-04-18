/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:57:48 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/13 17:10:00 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (((sub = (char *)malloc(sizeof(char) * (len + 1))) == 0) || !(s))
		return (0);
	if (s)
	{
		while (i < len)
		{
			sub[i] = s[i + start];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}
