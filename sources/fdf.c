/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:48:18 by acoezard          #+#    #+#             */
/*   Updated: 2021/10/29 18:05:38 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_line(t_fdf *fdf, t_vector *a, t_vector *b)
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
		mlx_pixel_put(fdf->mlx, fdf->window, X, Y, 0x00ff00);
		X += Xinc;
		Y += Yinc;
		i++;
    }
}

int	ft_mouse_event(int button, int x, int y, void *param)
{
	static t_vector *a;
	static t_vector *b;
	t_fdf	*fdf;

	if (button == MOUSE_LEFT)
		a = ft_vector_init(x, y, 0);
	if (button == MOUSE_RIGHT)
		b = ft_vector_init(x, y, 0);
	if (button == MOUSE_WHEEL)
	{
		fdf = (t_fdf *) param;
		ft_draw_line(fdf, a, b);
		ft_vector_free(a);
		ft_vector_free(b);
	}
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_fdf	fdf;

	fdf.mlx = mlx_init();
	fdf.window = mlx_new_window(fdf.mlx, 1000, 1000, "Hello world!");
	t_vector *a = ft_vector_init(100, 100, 1);
	t_vector *b = ft_vector_init(200, 100, 1);
	t_vector *c = ft_vector_init(100, 200, 1);
	t_vector *d = ft_vector_init(338, 150, 238);
	ft_vector_mul(a, 3);
	ft_vector_mul(b, 3);
	ft_vector_mul(c, 3);
	ft_vector_mul(d, 3);
	ft_draw_line(&fdf, a, b);
	ft_draw_line(&fdf, a, c);
	ft_draw_line(&fdf, a, d);
	//mlx_mouse_hook(fdf.window, ft_mouse_event, &fdf);
	mlx_loop(fdf.mlx);
	return (EXIT_SUCCESS);
}

