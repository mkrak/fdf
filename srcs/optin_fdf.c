/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optin_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:45:19 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 21:52:44 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	commands(t_coef *axes)
{
	mlx_string_put(axes->mlx, axes->win, 10, 10, 0xFFFFFF,
			"[-][COMMANDS - [FdF42 - sbelazou]][-]");
	mlx_string_put(axes->mlx, axes->win, 10, 30, 0xFFFFFF,
			"[9 6] : Zoom avant, Zoom arriere");
	mlx_string_put(axes->mlx, axes->win, 10, 50, 0xFFFFFF,
			"[+ -] : Plus haut, Moins haut");
	mlx_string_put(axes->mlx, axes->win, 10, 70, 0xFFFFFF,
			"[Up Down] : Aller vers le haut, Aller vers le bas");
	mlx_string_put(axes->mlx, axes->win, 10, 90, 0xFFFFFF,
			"[Left Right] : Aller vers la gauche, Aller vers la droite");
}
