/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:05:06 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/16 18:38:50 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*itoa;
	int		neg;
	int		i;

	i = 0;
	neg = FT_NEG(n);
	neg ? itoa = ft_strnew(ft_size(n) + 1) : 0;
	!neg ? itoa = ft_strnew(ft_size(n)) : 0;
	if (!(itoa))
		return (NULL);
	if (n == 0)
	{
		itoa[i++] = '0';
		itoa[i] = '\0';
		return (itoa);
	}
	while (n)
	{
		itoa[i++] = FT_ABS(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		itoa[i++] = '-';
	itoa[i] = '\0';
	return (ft_strrev(itoa));
}
