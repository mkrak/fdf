/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:55:59 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/19 17:09:49 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	n = FT_ABS(n);
	if (n >= 10)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10 + '0'), fd);
}
