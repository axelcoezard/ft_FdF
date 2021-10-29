/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:48:31 by acoezard          #+#    #+#             */
/*   Updated: 2021/10/29 15:59:15 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "mlx.h"

# define MOUSE_LEFT		1
# define MOUSE_RIGHT	1
# define MOUSE_WHEEL	1

struct s_fdf
{
	void*	mlx;
	void*	window;
};
typedef struct s_fdf	t_fdf;

#endif
