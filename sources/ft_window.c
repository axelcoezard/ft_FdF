/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:32:44 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/01 12:11:01 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*ft_window_open(int width, int height)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->width = width;
	fdf->height = height;
	fdf->window = mlx_new_window(fdf->mlx, width, height, "FdF");
	mlx_hook(fdf->window, 2, 1L<<0, ft_keypress_hook, fdf);
	mlx_mouse_hook(fdf->window, ft_mouse_hook, fdf);
	mlx_loop_hook(fdf->mlx, ft_loop_hook, fdf);
	mlx_loop(fdf->mlx);
	return (fdf);
}

void	ft_window_close(t_fdf *fdf)
{
	if (fdf != NULL)
	{
		mlx_destroy_window(fdf->mlx, fdf->window);
		free(fdf);
		exit(EXIT_SUCCESS);
	}
}
