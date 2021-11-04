/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:38:49 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/04 17:37:07 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void    ft_draw_line(t_fdf *fdf, t_vector2 *a, t_vector2 *b, int color)
{
    int    i;
    int dx = b->x - a->x;
    int dy = b->y - a->y;

    int steps = ft_max(ft_abs(dx), ft_abs(dy));
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
    free(a);
    free(b);
}

/*
void	ft_draw_line(t_fdf *fdf, t_vector2 *a, t_vector2 *b, int color)
{
	t_vector2	*c;
	t_vector2	*delta;
	int			steps;
	int			i;

	c = ft_vector2_init(a->x, a->y);
	delta = ft_vector2_init(b->x - a->x, b->y - b->y);
	steps = ft_max(ft_abs(delta->x), ft_abs(delta->y));
	i = 0;
	while (i <= steps)
	{
		ft_draw_pixel(fdf, c->x, c->y, color);
		c->x = c->x + (float)delta->x / steps;
		c->y = c->y + (float)delta->y / steps;

		i++;
	}
	free(a);
	free(b);
}
*/
void	ft_draw_text(t_fdf *fdf, int x, int y, char *text)
{
	mlx_string_put(fdf->mlx, fdf->window, x, y, 0x1e3799, text);
}

void	ft_draw_projection(t_fdf *fdf, int x, int y, int drawcode)
{
	t_vector2	*a;
	t_vector2	*b;
	int			color;

	color = 0x000000;
	a = ft_projection(ft_map_get_point(fdf->map, x, y), fdf);
	if (drawcode == DRAW_HORIZONTAL)
		b = ft_projection(ft_map_get_point(fdf->map, x + 1, y), fdf);
	else
	{
		b = ft_projection(ft_map_get_point(fdf->map, x, y + 1), fdf);
		color = 0x0000f0;
	}
	ft_draw_line(fdf, a, b, color);
}
