/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:30:25 by mkrakows          #+#    #+#             */
/*   Updated: 2016/12/01 17:46:46 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		size;

	size = ft_strlen(s1);
	if (!(dup = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dup = ft_strcpy(dup, (char *)s1);
	return (dup);
}
