#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_mycoef
{
	double	coef;
	double 	**map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		sl;
	int		xi;
	int		yi;
}			s_coef;

void				put_pixel(s_coef *scoef, int x, int y, int color);
void				ft_line(s_coef *scoef, int xi, int yi, int xf, int yf);
static int			ft_countword(char const *s);
int					*ft_read(char **av);
int					**ft_map(s_coef *scoef, int x, int y, char **av);
int					ft_window(s_coef *scoef, double **map, double coef);
void				new_image(s_coef *scoef);
int					ft_keyhock(int key, s_coef *param);


#endif
