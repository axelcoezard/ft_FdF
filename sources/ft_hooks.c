/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:41:34 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/01 12:24:55 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_loop_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) param;
	ft_window_clear(fdf);
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
	static t_vector2 *a;
	static t_vector2 *b;
	t_fdf	*fdf;

	if (button == MOUSE_LEFT)
		a = ft_vector2_init(x, y);
	if (button == MOUSE_RIGHT)
		b = ft_vector2_init(x, y);
	if (button == MOUSE_WHEEL)
	{
		fdf = (t_fdf *) param;
		ft_draw_line(fdf, a, b, 0x00ff00);
		free(a);
		free(b);
	}
	return (EXIT_SUCCESS);
}

int	ft_key_press_hook(int keycode, t_fdf* fdf)
{
	if (keycode == KEY_ESCAPE)
		ft_window_close(fdf);
	return (EXIT_SUCCESS);
}
