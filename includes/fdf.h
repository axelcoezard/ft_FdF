/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:48:31 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/01 12:04:54 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "mlx.h"

# define MOUSE_LEFT		1
# define MOUSE_RIGHT	2
# define MOUSE_WHEEL	3

# define KEY_ESCAPE		53
# define KEY_LEFT		123
# define KEY_UP			126
# define KEY_RIGHT		124
# define KEY_DOWN		125

struct s_fdf
{
	void*	mlx;
	void*	window;
	int		width;
	int		height;
};
typedef struct s_fdf	t_fdf;

t_fdf	*ft_window_open(int width, int height);
void	ft_window_close(t_fdf *fdf);

int		ft_loop_hook(void);
int		ft_mouse_hook(int button, int x, int y, void *param);
int		ft_keypress_hook(int keycode, t_fdf* fdf);

void	ft_draw_line(t_fdf *fdf, t_vector2 *a, t_vector2 *b, int color);

#endif
