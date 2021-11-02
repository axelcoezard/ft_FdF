/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:37:20 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/02 16:38:04 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector3	*ft_rotate_x(t_vector3 *vector, double alpha)
{
	int		y;

	y = vector->y;
	vector->y = y * cos(alpha) + vector->z * sin(alpha);
	vector->z = -y * sin(alpha) + vector->z * cos(alpha);
	return (vector);
}

t_vector3	*ft_rotate_y(t_vector3 *vector, double beta)
{
	int		x;

	x = vector->x;
	vector->x = x * cos(beta) + vector->z * sin(beta);
	vector->z = -x * sin(beta) + vector->z * cos(beta);
	return (vector);
}

t_vector3	*ft_rotate_z(t_vector3 *vector, double gamma)
{
	int		x;
	int		y;

	x = vector->x;
	y = vector->y;
	vector->x = x * cos(gamma) - y * sin(gamma);
	vector->y = x * sin(gamma) + y * cos(gamma);
	return (vector);
}

static t_vector2	*ft_projection_iso(t_vector3 *vector, t_camera *camera)
{
	t_vector2	*save;
	int		x;
	int		y;

	x = (vector->x - vector->y) * cos(0.6);
	y = (vector->x + vector->y) * sin(-0.6) - vector->z;
	x = x * camera->zoom + camera->x;
	y = y * camera->zoom + camera->y;
	save = ft_vector2_init(x, y);
	return (save);
}

t_vector2	*ft_projection(t_vector3 *vector, t_camera *camera)
{
	//vector = ft_rotate_x(vector, camera->alpha);
	//vector = ft_rotate_y(vector, camera->beta);
	//vector = ft_rotate_z(vector, camera->gamma);
	return (ft_projection_iso(vector, camera));
}
