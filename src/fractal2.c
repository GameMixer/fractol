/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:22:52 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/23 17:26:23 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		fractal_tricorn(t_win *pic, t_fract fract, t_point *point)
{
	fract.c = num_to_complex(point->x, point->y, fract, pic);
	while ((fract.z.r * fract.z.r + fract.z.i * fract.z.i) < 4 &&
			fract.iter < fract.max)
	{
		fract.tmp = fract.z.r;
		fract.z.r = fract.z.r * fract.z.r - fract.z.i * fract.z.i + fract.c.r;
		fract.z.i = -2 * fract.z.i * fract.tmp + fract.c.i;
		(fract.iter)++;
	}
	if (fract.iter == fract.max)
		return (pic->palette[pic->pnum].color_0);
	return (color_smooth(fract.z, fract, pic));
}
