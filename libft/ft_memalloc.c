/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:22:14 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/08 18:33:58 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*adr;
	size_t	i;

	i = 0;
	if ((adr = malloc(size)) == 0)
		return (NULL);
	while (i < size)
	{
		((char *)adr)[i] = 0;
		i++;
	}
	return (adr);
}
