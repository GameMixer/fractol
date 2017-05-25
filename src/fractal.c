/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:02:48 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/23 17:33:13 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractal_change(char *str, t_win *pic)
{
	if (ft_strcmp("mandelbrot", str) == 0)
		pic->fract_ptr = &(pic->fract_arr[0]);
	else if (ft_strcmp("julia", str) == 0)
		pic->fract_ptr = &(pic->fract_arr[1]);
	else if (ft_strcmp("burning_ship", str) == 0)
		pic->fract_ptr = &(pic->fract_arr[2]);
	else if (ft_strcmp("dragon", str) == 0)
		pic->fract_ptr = &(pic->fract_arr[3]);
	else
		pic->fract_ptr = &(pic->fract_arr[4]);
}

int		fractal_mandelbrot(t_win *pic, t_fract fract, t_point *point)
{
	fract.c = num_to_complex(point->x, point->y, fract, pic);
	while ((fract.z.r * fract.z.r + fract.z.i * fract.z.i) < 4 &&
			fract.iter < fract.max)
	{
		fract.tmp = fract.z.r;
		fract.z.r = fract.z.r * fract.z.r - fract.z.i * fract.z.i + fract.c.r;
		fract.z.i = 2 * fract.z.i * fract.tmp + fract.c.i;
		(fract.iter)++;
	}
	if (fract.iter == fract.max)
		return (pic->palette[pic->pnum].color_0);
	return (color_smooth(fract.z, fract, pic));
}

int		fractal_julia(t_win *pic, t_fract fract, t_point *point)
{
	fract.z = num_to_complex(point->x, point->y, fract, pic);
	while ((fract.z.r * fract.z.r + fract.z.i * fract.z.i) < 4 &&
			fract.iter < fract.max)
	{
		fract.tmp = fract.z.r;
		fract.z.r = fract.z.r * fract.z.r - fract.z.i * fract.z.i + fract.c.r;
		fract.z.i = 2 * fract.z.i * fract.tmp + fract.c.i;
		(fract.iter)++;
	}
	if (fract.iter == fract.max)
		return (pic->palette[pic->pnum].color_0);
	return (color_smooth(fract.z, fract, pic));
}

int		fractal_burn_ship(t_win *pic, t_fract fract, t_point *point)
{
	fract.c = num_to_complex(point->x, point->y, fract, pic);
	while ((fract.z.r * fract.z.r + fract.z.i * fract.z.i) < 4 &&
			(fract.iter < fract.max))
	{
		fract.tmp = fract.z.r;
		fract.z.r = fract.z.r * fract.z.r - fract.z.i * fract.z.i - fract.c.r;
		fract.z.i = 2 * fabs(fract.z.i) * fabs(fract.tmp) + fract.c.i;
		(fract.iter)++;
	}
	if (fract.iter == fract.max)
		return (pic->palette[pic->pnum].color_0);
	return (color_smooth(fract.z, fract, pic));
}

int		fractal_dragon(t_win *pic, t_fract fract, t_point *point)
{
	fract.c = num_to_complex(point->x, point->y, fract, pic);
	while ((fract.z.r * fract.z.r + fract.z.i * fract.z.i) < 4 &&
			(fract.iter < fract.max))
	{
		fract.tmp = fract.z.r;
		fract.z.r = fract.z.r * fract.z.r * fract.z.r -
			(3 * fract.z.r * fract.z.i * fract.z.i) + fract.c.r;
		fract.z.i = (3 * fract.tmp * fract.tmp * fract.z.i) + fract.c.i;
		(fract.iter)++;
	}
	if (fract.iter == fract.max)
		return (pic->palette[pic->pnum].color_0);
	return (color_smooth(fract.z, fract, pic));
}
