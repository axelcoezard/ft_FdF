/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:00:06 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/05 15:26:14 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_check(char *filename, t_fdf *fdf)
{
	int		filedesc;

	(void) fdf;
	filedesc = open(filename, O_RDONLY);
	if (filedesc > 0)
	{

		return (1);
	}
	return (0);
}

