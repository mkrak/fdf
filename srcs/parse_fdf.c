/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:34 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 22:03:34 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					ft_countword(char const *s)
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

int					ft_open(char *str)
{
	int fd;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		exit(-1);
	}
	return (fd);
}

int					*ft_read(char **av)
{
	int		fd;
	char	*line;
	int		*tab;

	tab = malloc(sizeof(int) * 2);
	tab[0] = 0;
	tab[1] = 0;
	fd = ft_open(av[1]);
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

int					**ft_map(t_coef *param, int x, int y, char **av)
{
	int		tab[4];
	char	*line;

	tab[1] = 0;
	tab[2] = 0;
	init_map(param, x, y);
	tab[3] = ft_open(av[1]);
	tab[0] = 0;
	while (get_next_line(tab[3], &line))
	{
		while (line[tab[0]] != '\0')
			if (line[tab[0]] == ' ')
				tab[0]++;
			else
			{
				param->map[tab[1]][tab[2]] = ft_atoi(&line[tab[0]]);
				tab[2]++;
				while (line[tab[0]] != ' ' && line[tab[0]])
					tab[0]++;
			}
		reset_v(&tab[0], &tab[1], &tab[2], &line);
	}
	param->map[tab[1]] = NULL;
	close(tab[3]);
	return (0);
}

void				put_pixel(t_coef *scoef, int x, int y, int color)
{
	int	i;

	if (x >= 2600 || x < 0 || y >= 1390 || y < 0)
		return ;
	i = x * 4 + y * scoef->sl;
	scoef->data[i] = color & 0xff;
	scoef->data[++i] = (color >> 8) & 0xff;
	scoef->data[++i] = (color >> 16);
}
