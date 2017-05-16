/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:02:48 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/09 17:56:14 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractal_change(char *str, t_win *pic)
{
	if (ft_strcmp("mandelbrot", str) == 0)
		pic->fract_ptr = &(pic->fract_arr[0]);
	else if (ft_strcmp("julia", str) == 0)
		pic->fract_ptr = &(pic->fract_arr[1]);
	else
		pic->fract_ptr = &(pic->fract_arr[2]);
}

int		fractal_mandelbrot(t_win *pic, t_fract fract, t_point *point)
{
	fract.c.r = 1.0 * (point->x - pic->win_w / 2) /
		(0.5 * fract.scale * pic->win_w) + fract.x1;
	fract.c.i = (point->y - pic->win_h / 2) /
		(0.5 * fract.scale * pic->win_h) + fract.y1;
	while ((fract.z.r * fract.z.r + fract.z.i * fract.z.i) < 4 &&
			fract.iter < fract.max)
	{
		fract.tmp = fract.z.r;
		fract.z.r = fract.z.r * fract.z.r - fract.z.i * fract.z.i + fract.c.r;
		fract.z.i = 2 * fract.z.i * fract.tmp + fract.c.i;
		(fract.iter)++;
	}
	if (fract.iter == fract.max)
		return (get_color(100, pic->palette[pic->pnum]));
	return (get_color((fract.iter * fract.iter) * 0.1,
				pic->palette[pic->pnum]));
}

int		fractal_julia(t_win *pic, t_fract fract, t_point *point)
{
	fract.z.r = 1.0 * (point->x - pic->win_w / 2) /
		(0.5 * fract.scale * pic->win_w) + fract.x1;
	fract.z.i = (point->y - pic->win_h / 2) /
		(0.5 * fract.scale * pic->win_h) + fract.y1;
	while ((fract.z.r * fract.z.r + fract.z.i * fract.z.i) < 4 &&
			fract.iter < fract.max)
	{
		fract.tmp = fract.z.r;
		fract.z.r = fract.z.r * fract.z.r - fract.z.i * fract.z.i + fract.c.r;
		fract.z.i = 2 * fract.z.i * fract.tmp + fract.c.i;
		(fract.iter)++;
	}
	if (fract.iter == fract.max)
		return (get_color(100, pic->palette[pic->pnum]));
	return (get_color((fract.iter * fract.iter) * 0.1,
				pic->palette[pic->pnum]));
}

int		fractal_burn_ship(t_win *pic, t_fract fract, t_point *point)
{
	fract.c.r = 1.0 * (point->x - pic->win_w / 2) /
		(0.5 * fract.scale * pic->win_w) + fract.x1;
	fract.c.i = (point->y - pic->win_h / 2) /
		(0.5 * fract.scale * pic->win_h) + fract.y1;
	while ((fract.z.r * fract.z.r + fract.z.i * fract.z.i) < 4 &&
			(fract.iter < fract.max))
	{
		fract.tmp = fract.z.r;
		fract.z.r = fract.z.r * fract.z.r - fract.z.i * fract.z.i - fract.c.r;
		fract.z.i = 2 * fabs(fract.z.i) * fabs(fract.tmp) + fract.c.i;
		(fract.iter)++;
	}
	if (fract.iter == fract.max)
		return (color_rgb(fract.iter * 255 / fract.max, 10, 0));
	return (color_rgb(fract.iter * 255 / fract.max,
				fract.iter * 255 / (fract.max * 2), 0));
}
