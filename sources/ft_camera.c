/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:47:53 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/04 17:20:37 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*ft_camera_init(t_fdf *fdf)
{
	fdf->camera = (t_camera *) malloc(sizeof(t_camera));
	fdf->camera->x = fdf->width / 2;
	fdf->camera->y = fdf->height / 2;
	fdf->camera->zoom = 1;
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	return (fdf);
}

void	ft_camera_controls(t_fdf *fdf)
{
	if (fdf->buttons[MOUSE_SCROLL_DOWN])
		ft_camera_zoom(fdf->camera, 1);
	if (fdf->buttons[MOUSE_SCROLL_UP])
		ft_camera_zoom(fdf->camera, -1);
	if (fdf->keyboard[KEY_LEFT] || fdf->keyboard[KEY_A])
		ft_camera_move(fdf->camera, -10, 0);
	if (fdf->keyboard[KEY_RIGHT] || fdf->keyboard[KEY_D])
		ft_camera_move(fdf->camera, 10, 0);
	if (fdf->keyboard[KEY_UP] || fdf->keyboard[KEY_W])
		ft_camera_move(fdf->camera, 0, -10);
	if (fdf->keyboard[KEY_DOWN] || fdf->keyboard[KEY_S])
		ft_camera_move(fdf->camera, 0, 10);
}

t_camera	*ft_camera_move(t_camera *camera, int x, int y)
{
	camera->x += x;
	camera->y += y;
	return (camera);
}

t_camera	*ft_camera_rotate(t_camera *camera, float a, float b, float g)
{
	camera->alpha += a;
	camera->beta += b;
	camera->gamma += g;
	return (camera);
}

t_camera	*ft_camera_zoom(t_camera *camera, int zoom)
{
	camera->zoom += zoom;
	return (camera);
}
