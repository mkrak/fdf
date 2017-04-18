/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 22:02:19 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_line(t_coef *s, int a[2], int x_b, int y_b)
{
	int dh;
	int dl;
	int c;
	int m;

	dh = x_b - a[0];
	dl = y_b - a[1];
	c = -1;
	m = abs(dh) > abs(dl) ? abs(dh) : abs(dl);
	while (++c < m)
		put_pixel(s, a[0] + c * dh / m, a[1] + c * dl / m, 0xffffff);
}

void				ft_xa(t_coef *s, int tab[2], double coef, double **map)
{
	int a[2];
	int b[2];

	a[0] = (tab[1] * 2) * coef + s->xi + ((tab[0] - 1) * 2) * coef;
	a[1] = (tab[0] - 1) * coef + s->yi - tab[1] * coef - s->cz *
		((map[tab[0] - 1][tab[1]] * 2) * coef);
	b[0] = (tab[1] * 2) * coef + s->xi + (tab[0] * 2) * coef;
	b[1] = tab[0] * coef + s->yi - tab[1] * coef - s->cz *
		((map[tab[0]][tab[1]] * 2) * coef);
	ft_line(s, a, b[0], b[1]);
}

void				ft_ya(t_coef *s, int tab[4], double coef, double **map)
{
	int b[2];

	b[0] = (tab[1] * 2) * coef + s->xi + (tab[0] * 2) * coef;
	b[1] = tab[0] * coef + s->yi - tab[1] * coef - s->cz *
		((map[tab[0]][tab[1]] * 2) * coef);
	ft_line(s, b, tab[2], tab[3]);
}

int					ft_window(t_coef *s, double **map, double c)
{
	int x;
	int y;
	int tab[4];

	x = 0;
	y = 0;
	while (map[x])
	{
		while (y < s->cw)
		{
			tab[0] = x;
			tab[1] = y;
			if (x)
				ft_xa(s, tab, c, map);
			if (y)
				ft_ya(s, tab, c, map);
			tab[2] = (y * 2) * c + s->xi + (x * 2) * c;
			tab[3] = x * c + s->yi - y * c - s->cz * ((map[x][y] * 2) * c);
			y++;
		}
		x++;
		y = 0;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

int					main(int ac, char **av)
{
	int		*tab;
	t_coef	*scoef;

	if (ac != 2)
	{
		ft_putendl("Usage : ../fdf <filename>");
		return (-1);
	}
	scoef = (t_coef*)malloc(sizeof(t_coef));
	init_struct(scoef);
	new_image(scoef);
	tab = ft_read(av);
	if (tab[0] == -1)
		return (-1);
	scoef->cw = tab[0];
	ft_map(scoef, tab[0], tab[1], av);
	mlx_hook(scoef->win, 2, 3, ft_keyhock, scoef);
	ft_window(scoef, scoef->map, scoef->coef);
	mlx_loop(scoef->mlx);
	free(scoef);
	return (0);
}
