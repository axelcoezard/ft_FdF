/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:32:08 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/01 12:53:40 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector2 **ft_parser(char *filename)
{
	char	*line;
	char	**points;
	int		filedesc;
	int		y;
	int		x;

	filedesc = open(filename, O_RDONLY);
	if (filedesc < 1)
		ft_printf("Error\n");
	line = ft_get_next_line(filedesc);
	y = 0;
	while (line != NULL)
	{
		points = ft_split(line, ' ');
		x = 0;
		while (points[x] != NULL)
		{
			ft_printf("Points x=%d y=%d hauteur=%d\n", x, y, ft_atoi(points[x]));
			x++;
		}
		line = ft_get_next_line(filedesc);
		y++;
	}
	close(filedesc);
	ft_printf("Shown\n");
	return (NULL);
}
