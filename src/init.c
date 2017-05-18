/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:16:57 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/18 13:05:37 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_palette(t_win *pic)
{
	if (!(pic->palette = (t_palette *)malloc(sizeof(t_palette) * PAL_SIZE)))
		fract_error_malloc();
	pic->palette[0] = (t_palette){BLACK, RED, 0xBF3F00, OLIVE,
		0x3FBF00, GREEN, 0x00BF3F, TEAL, 0x003FBF, BLUE};
	pic->palette[1] = (t_palette){BLACK, GRAY87, GRAY80, GRAY73,
		GRAY67, GRAY60, GRAY53, GRAY47, GRAY40, GRAY33};
	pic->palette[2] = (t_palette){RED, MAROON, FIREBRICK, INDIANRED,
		CRIMSON, RED, ORANGERED, ORANGE, GOLDENROD1, YELLOW};
	pic->palette[3] = (t_palette){IVORYBLACK, NAVY, COBALT, ROYALBLUE,
		CORNFLOWERBLUE, STEELBLUE1, SKYBLUE, CADETBLUE1, LITBLUE1, AZURE};
	pic->pnum = 0;
}

void	init_fract(t_win *pic)
{
	if (!(pic->fract_arr = (t_fract *)malloc(sizeof(t_fract) * FRACTALS)))
		fract_error_malloc();
	pic->fract_arr[0] = (t_fract){{0, 0}, {0, 0}, -2, 1, -1, 1,
		-0.5, 0, 1, 0, 0, MAX_START, fractal_mandelbrot};
	pic->fract_arr[1] = (t_fract){{0, 0}, {0, 0}, -2, 2, -2, 2,
		0, 0, 1, 0, 0, MAX_START, fractal_julia};
	pic->fract_arr[2] = (t_fract){{0, 0}, {0, 0}, -2, 1, -2, 1,
		-0.25, 0, 1, 0, 0, MAX_START, fractal_burn_ship};
	pic->fract_ptr = &(pic->fract_arr[0]);
}
