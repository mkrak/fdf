/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:53:41 by mkrakows          #+#    #+#             */
/*   Updated: 2017/03/29 15:45:31 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||\
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(char *str)
{
	size_t	i;
	int		res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			sign = (str[i] == '+') ? 1 : -1;
			i++;
		}
		else
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	res = res * sign;
	return (res);
}
