#include "fdf.h"

static int			ft_countword(char const *s)
{
	int i;
	int	mots;

	i = 0;
	mots = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
		{
			mots++;
			while (s[i] != ' ' && s[i])
				i++;
		}
	}
	return (mots);
}

int					*ft_read(char **av)
{
	int		fd;
	char	*line;
	int		*tab;

	tab = malloc(sizeof(int) * 2);
	tab[0] = 0;
	tab[1] = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (tab[0] == 0)
			tab[0] = ft_countword(line);
		if (ft_countword(line) < tab[0])
		{
			ft_putendl("Found wrong line length. Exiting.");
			tab[0] = -1;
			return (tab);
		}
		tab[1]++;
		line = NULL;
		free(line);
	}
	close(fd);
	return (tab);
}

int				**ft_map(s_coef *param, int x, int y, char **av)
{
	int		i;
	int		fd;
	char	*line;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	param->map = malloc(sizeof(double*) * y + 1);
	while (i != y + 1)
		param->map[i++] = malloc(sizeof(double) * x + 1);
	fd = open(av[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		while (line[i] != '\0')
		{
			if (line[i] == ' ')
				i++;
			else
			{
				param->map[j][k] = ft_atoi(&line[i]);
				k++;
				while (line[i] != ' ' && line[i])
					i++;
			}
		}
		param->map[j][k] = -1;
		j++;
		k = 0;
		i = 0;
		line = NULL;
		free(line);
	}
	param->map[j] = NULL;
	close(fd);
	return (0);
}

void				put_pixel(s_coef *scoef, int x, int y, int color)
{
	int	i;

	if (x >= 2600 || x < 0 || y >= 1390 || y < 0)
		return ;
	i = x * 4 + y * scoef->sl;
	scoef->data[i] = color & 0xff;
	scoef->data[++i] = (color >> 8) & 0xff;
	scoef->data[++i] = (color >> 16);
}
