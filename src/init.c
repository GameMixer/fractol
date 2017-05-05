/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:16:57 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/04 18:54:53 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_fract(t_win *pic)
{
	if (!(pic->fract_arr = (t_fract *)malloc(sizeof(t_fractal) * FRACTALS)))
		fract_error_malloc();
	pic->fract_arr[0] = (t_fract){{0, 0}, {0, 0}, 0, 0, 0, 0,
		pic->win_w / 2, pic->win_h / 2, 0.5, 0, 0, 50, fractal_mandelbrot};
	pic->fract_arr[1] = (t_fract){{0, 0}, {0, 0}, 0, 0, 0, 0,
		pic->win_w / 2, pic->win_h / 2, 0.5, 0, 0, 10, fractal_julia};
	pic->fract_arr[2] = (t_fract){{0, 0}, {0, 0}, 0, 0, 0, 0,
		pic->win_w / 2, pic->win_h / 2, 0.5, 0, 0, 50, fractal_};
	pic->fract_ptr = &(pic->fract_arr[0]);
}
