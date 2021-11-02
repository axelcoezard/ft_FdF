/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:37:20 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/02 09:53:48 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vector3	*ft_rotate_x(t_vector3 *vector, double alpha)
{
	int		y;

	y = vector->y;
	vector->y = y * cos(alpha) + vector->z * sin(alpha);
	vector->z = -y * sin(alpha) + vector->z * cos(alpha);
	return (vector);
}

static t_vector3	*ft_rotate_y(t_vector3 *vector, double beta)
{
	int		x;

	x = vector->x;
	vector->x = x * cos(beta) + vector->z * sin(beta);
	vector->z = -x * sin(beta) + vector->z * cos(beta);
	return (vector);
}

static t_vector3	*ft_rotate_z(t_vector3 *vector, double gamma)
{
	int		x;
	int		y;

	x = vector->x;
	y = vector->y;
	vector->x = x * cos(gamma) - y * sin(gamma);
	vector->y = x * sin(gamma) + y * cos(gamma);
	return (vector);
}

static t_vector2	*ft_projection_iso(t_vector3 *vector)
{
	t_vector2	*save;
	int		x;
	int		y;

	x = (vector->x - vector->y) * cos(0.523599);
	y = (vector->x + vector->y) * sin(0.523599) - vector->z;
	save = ft_vector2_init(x, y);
	return (save);
}

t_vector2	*ft_projection(t_vector3 *vector, int alpha, int beta, int gamma)
{
	vector = ft_rotate_x(vector, alpha);
	vector = ft_rotate_y(vector, beta);
	vector = ft_rotate_z(vector, gamma);
	return (ft_projection_iso(vector));
}
