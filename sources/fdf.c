/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:48:18 by acoezard          #+#    #+#             */
/*   Updated: 2021/10/29 15:03:06 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"



int	ft_mouse_event(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) param;
	ft_printf("%d %d %d", button);
	mlx_pixel_put(fdf->mlx, fdf->window, x, y, 0x00ff00);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_fdf	fdf;

	fdf.mlx = mlx_init();
	fdf.window = mlx_new_window(fdf.mlx, 1920, 1080, "Hello world!");
	mlx_mouse_hook(fdf.window, ft_mouse_event, &fdf);
	mlx_loop(fdf.mlx);
	return (EXIT_SUCCESS);
}

