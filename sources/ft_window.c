/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:32:44 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/02 14:37:03 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*ft_window_open(int width, int height)
{
	t_fdf	*fdf;
	int		n;

	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->width = width;
	fdf->height = height;
	fdf->window = mlx_new_window(fdf->mlx, width, height, "FdF");
	fdf->image = mlx_new_image(fdf->mlx, width, height);
	fdf->buffer = (int *) mlx_get_data_addr(fdf->image, &n, &n, &n);
	mlx_hook(fdf->window, 2, 1L << 0, ft_key_press_hook, fdf);
	mlx_hook(fdf->window, 3, 1L << 1, ft_key_release_hook, fdf);
	mlx_hook(fdf->window, 17, 0L, ft_quit_hook, fdf);
	mlx_mouse_hook(fdf->window, ft_mouse_hook, fdf);
	return (fdf);
}

void	ft_window_loop(t_fdf *fdf, int (*hook)())
{
	if (fdf != NULL)
	{
		mlx_loop_hook(fdf->mlx, hook, fdf);
		mlx_loop(fdf->mlx);
	}
}

void	ft_window_update(t_fdf *fdf)
{
	if (fdf != NULL)
	{
		mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	}
}

void	ft_window_clear(t_fdf *fdf, int color)
{
	int		x;

	x = fdf->width * fdf->height - 1;
	while (x >= 0)
	{
		fdf->buffer[x] = color;
		x--;
	}
}

void	ft_window_close(t_fdf *fdf)
{
	if (fdf != NULL)
	{
		mlx_destroy_window(fdf->mlx, fdf->window);
		free(fdf->camera);
		free(fdf);
		exit(EXIT_SUCCESS);
	}
}
