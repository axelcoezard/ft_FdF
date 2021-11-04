/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:41:34 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/04 15:17:18 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_loop_hook(t_fdf *fdf)
{
	int		x;
	int		y;

	ft_window_clear(fdf, 0xebebeb);
	ft_camera_controls(fdf);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				ft_draw_projection(fdf, x, y, DRAW_HORIZONTAL);
			if (y + 1 < fdf->map->height)
				ft_draw_projection(fdf, x, y, DRAW_VERTICAL);
			x++;
		}
		y++;
	}
	ft_window_update(fdf);
	ft_draw_text(fdf, 20, 20, "Hello world");
	return (EXIT_SUCCESS);
}

int	ft_quit_hook(t_fdf *fdf)
{
	ft_window_close(fdf);
	return (EXIT_SUCCESS);
}
