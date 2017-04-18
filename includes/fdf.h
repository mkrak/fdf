/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 22:00:46 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct		s_mycoef
{
	double		coef;
	double		**map;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			sl;
	int			xi;
	int			yi;
	double		cz;
	int			cw;
}					t_coef;

void				ft_line(t_coef *s, int a[2], int x_b, int y_b);
void				ft_xa(t_coef *s, int tab[2], double coef, double **map);
void				ft_ya(t_coef *s, int tab[4], double coef, double **map);
int					ft_window(t_coef *s, double **map, double c);
void				reset_v(int *i, int *j, int *k, char **line);
void				init_map(t_coef *s, int x, int y);
void				new_image(t_coef *scoef);
void				init_struct(t_coef *scoef);
int					ft_keyhock(int key, t_coef *param);
int					ft_countword(char const *s);
int					ft_open(char *str);
int					*ft_read(char **av);
int					**ft_map(t_coef *param, int x, int y, char **av);
void				put_pixel(t_coef *scoef, int x, int y, int color);
#endif
