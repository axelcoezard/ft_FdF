/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:41:34 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/02 16:35:23 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_loop_hook(void *param)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	fdf = (t_fdf *) param;
	ft_window_clear(fdf, 0xebebeb);
	ft_camera_controls(fdf);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				ft_draw_horizontal(fdf, x, y);
			if (y < fdf->map->height - 1)
				ft_draw_vertical(fdf, x, y);
			x++;
		}
		y++;
	}
	ft_window_update(fdf);
	return (EXIT_SUCCESS);
}

int	ft_quit_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) param;
	ft_window_close(fdf);
	return (EXIT_SUCCESS);
}

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void) x;
	(void) y;
	fdf = (t_fdf *) param;
	if (button == 5)
		ft_camera_zoom(fdf->camera, 1);
	if (button == 4)
		ft_camera_zoom(fdf->camera, -1);
	return (EXIT_SUCCESS);
}

int	ft_key_press_hook(int keycode, t_fdf* fdf)
{
	if (keycode == KEY_ESCAPE)
		ft_window_close(fdf);
	fdf->keyboard[keycode] = 1;
	ft_loop_hook(fdf);
	return (EXIT_SUCCESS);
}

int	ft_key_release_hook(int keycode, t_fdf* fdf)
{
	fdf->keyboard[keycode] = 0;
	return (EXIT_SUCCESS);
}
