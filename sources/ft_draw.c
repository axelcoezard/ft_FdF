/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:38:49 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/01 11:39:40 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		mlx_pixel_put(fdf->mlx, fdf->window, X, Y, color);
		X += Xinc;
		Y += Yinc;
		i++;
    }
}
