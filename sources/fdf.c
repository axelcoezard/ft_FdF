/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:48:18 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/01 12:41:12 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	t_fdf *fdf;

	ft_parser("./maps/10-2.fdf");
	fdf = ft_window_open(400, 400);
	return (EXIT_SUCCESS);
}

