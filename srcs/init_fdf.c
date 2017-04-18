/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:02:30 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 21:47:35 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				reset_v(int *i, int *j, int *k, char **line)
{
	*j += 1;
	*k = 0;
	*i = 0;
	*line = NULL;
	free(*line);
}

void				init_map(t_coef *s, int x, int y)
{
	int	i;

	i = 0;
	s->map = malloc(sizeof(double*) * y);
	while (i < y)
		s->map[i++] = malloc(sizeof(double) * x);
}

void				new_image(t_coef *scoef)
{
	int		bpp;
	int		endian;

	scoef->img = mlx_new_image(scoef->mlx, 2600, 1390);
	scoef->data = mlx_get_data_addr(scoef->img, &bpp, &scoef->sl, &endian);
}

void				init_struct(t_coef *scoef)
{
	scoef->coef = 2;
	scoef->xi = 40;
	scoef->yi = 600;
	scoef->cz = 1;
	scoef->mlx = mlx_init();
	scoef->win = mlx_new_window(scoef->mlx, 2600, 1390, "mlx 42");
}

int					ft_keyhock(int key, t_coef *param)
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
	else if (key == 33)
		param->cz -= 0.2;
	else if (key == 30)
		param->cz += 0.2;
	else
		return (0);
	mlx_destroy_image(param->mlx, param->img);
	new_image(param);
	ft_window(param, param->map, param->coef);
	return (0);
}
