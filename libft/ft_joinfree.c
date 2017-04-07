/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:02:34 by mkrakows          #+#    #+#             */
/*   Updated: 2017/02/28 07:54:25 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *s1, char *s2, char **addr)
{
	char	*join;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((join = ft_strnew(len)) == 0)
		return (NULL);
	join = ft_strcpy(join, (char*)s1);
	join = ft_strcat(join, s2);
	if (addr)
		free(*addr);
	return (join);
}
