/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:41:29 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/02 18:34:30 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	j;

	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[j])
	{
		if (big[j] == little[0])
		{
			if (ft_strncmp((big + j), little, ft_strlen(little)) == 0)
				return ((char *)big + j);
		}
		j++;
	}
	return (NULL);
}
