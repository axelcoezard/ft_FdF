/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:32:08 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/04 17:32:45 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*ft_parser_get_line(int filedesc)
{
	char	*line;

	line = ft_get_next_line(filedesc);
	if (line == NULL)
		return (NULL);
	return (ft_strtrim(line, " \n"));
}

static t_fdf	*ft_parser_get_dimension(char *filename, t_fdf *fdf)
{
	int			filedesc;
	char		*line;
	char		**line_values;

	filedesc = open(filename, O_RDONLY);
	if (filedesc > 0)
	{
		line = ft_parser_get_line(filedesc);
		line_values = ft_split(line, ' ');
		while (line_values[fdf->map->width] != NULL)
			fdf->map->width++;
		free(line_values);
		while (line != NULL)
		{
			free(line);
			line = ft_parser_get_line(filedesc);
			fdf->map->height++;
		}
		close(filedesc);
	}
	return (fdf);
}

t_fdf	*ft_parser(t_fdf *fdf, char *filename)
{
	char	*line;
	char	**points;
	int		filedesc;
	int		y;
	int		x;

	fdf = ft_map_init(fdf, 0, 0);
	fdf = ft_parser_get_dimension(filename, fdf);
	fdf->map = ft_map_init_points(fdf->map);
	filedesc = open(filename, O_RDONLY);
	if (filedesc < 1)
		ft_printf("Error\n");
	line = ft_parser_get_line(filedesc);
	y = 0;
	while (line != NULL)
	{
		points = ft_split(line, ' ');
		x = -1;
		while (points[++x] != NULL)
			ft_map_set_point(fdf->map, x, y, ft_atoi(points[x]));
		line = ft_parser_get_line(filedesc);
		y++;
	}
	close(filedesc);
	return (fdf);
}
