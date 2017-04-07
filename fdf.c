#include "fdf.h"

void				ft_line(s_coef *scoef, int xi, int yi, int xf, int yf)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	put_pixel(scoef, x, y, 0x0000ff);
	if (dx > dy) 
	{
		cumul = dx / 2;
		for (i = 1; i <= dx; i++)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			put_pixel(scoef, x, y, 0x00ff00);
		}
	}
	else
	{
		cumul = dy / 2;
		for (i = 1; i <= dy; i++)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			put_pixel(scoef, x, y, 0xff0000);
		}
	}
}

int					ft_window(s_coef *s, double **map, double coef)
{
	int x;
	int y;
	int tmpx;
	int tmpy;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y] != -1)
		{
			if (x)
				ft_line(s, (y * 2) * coef + s->xi + ((x - 1) * 2) * coef,
				(x - 1) * coef + s->yi - y * coef - ((map[x - 1][y] * 2) *
				coef), (y * 2) * coef + s->xi + (x * 2) * coef, x * coef +
				s->yi - y * coef - ((map[x][y] * 2) * coef));
			if (y)
				ft_line(s, tmpx, tmpy, (y * 2) * coef + s->xi + (x * 2) *
				coef, x * coef + s->yi - y * coef - ((map[x][y] * 2) * coef));
			tmpx = (y * 2) * coef + s->xi + (x * 2) * coef;
			tmpy = x * coef + s->yi - y * coef - ((map[x][y] * 2) * coef);
			y++;
		}
		x++;
		y = 0;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

void				new_image(s_coef *scoef)
{
	int		bpp;
	int		endian;

	scoef->img = mlx_new_image(scoef->mlx, 2600, 1390);
	scoef->data = mlx_get_data_addr(scoef->img, &bpp, &scoef->sl, &endian);
}

int					ft_keyhock(int key, s_coef *param)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 69)
		param->coef *= 1.05f;
	else if (key == 78)
		param->coef *= 0.95f;
	else if (key == 123)
		param->xi -= 10;
	else if (key == 124)
		param->xi += 10;
	else if (key == 125)
		param->yi += 10;
	else if (key == 126)
		param->yi -= 10;
	else
		return (0);
	mlx_destroy_image(param->mlx, param->img);
	new_image(param);
	ft_window(param, param->map, param->coef);
	return (0);
}

int					main(int ac, char **av)
{
	int		*tab;
	s_coef	*scoef;

	if (ac != 2)
	{
		ft_putendl("Usage : ../fdf <filename>");
		return (-1);
	}
	scoef = (s_coef*)malloc(sizeof(s_coef));
	scoef->coef = 2;
	scoef->xi = 40;
	scoef->yi = 600;
	scoef->mlx = mlx_init();
	scoef->win = mlx_new_window(scoef->mlx, 2600, 1390, "mlx 42");
	new_image(scoef);
	tab = ft_read(av);
	if (tab[0] == -1)
		return (-1);
	ft_map(scoef, tab[0], tab[1], av);
	mlx_hook(scoef->win, 2, 3, ft_keyhock, scoef);
	ft_window(scoef, scoef->map, scoef->coef);
	mlx_loop(scoef->mlx);
	free(scoef);
	return (0);
}
