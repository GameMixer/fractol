/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:07:05 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/23 17:38:12 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fract_error_malloc(void)
{
	ft_putstr("malloc error\n");
	exit(1);
}

void	fract_error_usage(void)
{
	ft_putstr("usage: fractol [mandelbrot, julia, burning_ship, ");
	ft_putstr("dragon, tricorn]\n");
	exit(2);
}

void	fract_error_mlx(void)
{
	ft_putstr("error mlx init.\n");
	exit(3);
}
