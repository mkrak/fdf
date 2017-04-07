/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:15:50 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/02 21:19:16 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;

	j = 0;
	if (*big)
	{
		if (len < ft_strlen(little))
			return (NULL);
		if (ft_strlen(little) == 0)
			return ((char *)big);
		while (big[j] && j < (len - ft_strlen(little) + 1))
		{
			if (big[j] == little[0])
			{
				if (ft_strncmp((big + j), little, ft_strlen(little)) == 0)
					return ((char *)big + j);
			}
			j++;
		}
	}
	return (NULL);
}
