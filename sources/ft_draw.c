/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:38:49 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/02 16:11:44 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_horizontal(t_fdf *fdf, int x, int y)
{
	t_vector2	*a;
	t_vector2	*b;

	a = ft_projection(ft_map_get_point(fdf->map, x, y), fdf->camera);
	b = ft_projection(ft_map_get_point(fdf->map, x + 1, y), fdf->camera);
	ft_draw_line(fdf, a, b, 0x000000);
}

void	ft_draw_vertical(t_fdf *fdf, int x, int y)
{
	t_vector2	*a;
	t_vector2	*b;

	a = ft_projection(ft_map_get_point(fdf->map, x, y), fdf->camera);
	b = ft_projection(ft_map_get_point(fdf->map, x, y + 1), fdf->camera);
	ft_draw_line(fdf, a, b, 0x0000f0);
}

void	ft_draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (fdf == NULL || fdf->buffer == NULL)
		return ;
	if (x < 0 || x > fdf->width - 1)
		return ;
	if (y < 0 || y > fdf->height - 1)
		return ;
	fdf->buffer[x + y * fdf->width] = color;
}

void	ft_draw_line(t_fdf *fdf, t_vector2 *a, t_vector2 *b, int color)
{
	int	i;
	int dx = b->x - a->x;
	int dy = b->y - a->y;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float Xinc = dx / (float) steps;
	float Yinc = dy / (float) steps;
	float X = a->x;
	float Y = a->y;
	i = 0;
	while (i <= steps)
	{
		ft_draw_pixel(fdf, X, Y, color);
		X += Xinc;
		Y += Yinc;
		i++;
    }
}
