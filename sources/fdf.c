/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:48:18 by acoezard          #+#    #+#             */
/*   Updated: 2021/10/29 16:02:42 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_mouse_event(int button, int x, int y, void *param)
{
	static t_vector *a = NULL;
	static t_vector *b = NULL;
	t_fdf	*fdf;

	if (button != MOUSE_LEFT)
		return (EXIT_FAILURE);
	if (a == NULL)
		a = ft_vector_init(x, y);
	if (a != NULL && b == NULL)
		b = ft_vector_init(x, y);
	if (a != NULL && b != NULL)
	{
		fdf = (t_fdf *) param;
		mlx_pixel_put(fdf->mlx, fdf->window, a->x, a->y, 0x00ff00);
		mlx_pixel_put(fdf->mlx, fdf->window, b->x, b->y, 0x00f0f0);
		ft_vector_free(a);
		ft_vector_free(b);
		a = NULL;
		b = NULL;
	}
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_fdf	fdf;

	fdf.mlx = mlx_init();
	fdf.window = mlx_new_window(fdf.mlx, 400, 400, "Hello world!");
	mlx_mouse_hook(fdf.window, ft_mouse_event, &fdf);
	mlx_loop(fdf.mlx);
	return (EXIT_SUCCESS);
}

