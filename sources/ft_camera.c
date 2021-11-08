/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:47:53 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/08 10:57:06 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	ft_camera_init(t_fdf *fdf)
{
	float	w;
	float	h;

	fdf->camera = (t_camera *) malloc(sizeof(t_camera));
	if (fdf->camera == NULL)
		return (0);
	w = fdf->map->width / fdf->width;
	h = fdf->map->height / fdf->height;
	fdf->camera->x = fdf->width / 2;
	fdf->camera->y = fdf->height / 2;
	fdf->camera->zoom = 10;
	printf("%f %f\n", w, h);
	return (1);
}
