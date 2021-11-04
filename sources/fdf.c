/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:48:18 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/04 17:20:24 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	(void) ac;
	fdf = ft_window_open(1280, 720);
	fdf = ft_camera_init(fdf);
	fdf = ft_parser(fdf, av[1]);
	ft_window_loop(fdf, ft_loop_hook);
	return (EXIT_SUCCESS);
}
