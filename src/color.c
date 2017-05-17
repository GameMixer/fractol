/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:53:36 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/16 17:26:40 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		color_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + ((b & 0xFF)));
}

int		color_smooth(t_complex z, t_fract f, t_win *pic)
{
	double	i;
	double	zn;
	double	nu;

	zn = log(z.r * z.r + z.i * z.i) / 2.0;
	nu = log(zn / log(2)) / log(2);
	i = f.iter + 1 - nu;
	if (i < 0)
		i = 0;
	return (get_color(i, f.max, pic));
}

int		get_color(double i, int max, t_win *pic)
{
	double	m;

	m = (double)max;
	if (i < m)
	{
		if (pic->pnum == 0)
		{
			if (i < (m / 2))
				return (color_rgb(((m / 2) - i) * 255 / (m / 2),
							i * 255 / (m / 2), 0));
			else
				return (color_rgb(0, ((m / 2) - (i - (m / 2))) * 255 / (m / 2),
							(i - (m / 2)) * 255 / (m / 2)));
		}
		else if (pic->pnum == 1)
			return (color_rgb(i * 255 / m, i * 255 / m, i * 255 / m));
		else if (pic->pnum == 2)
			return (color_rgb(i * 255 / m, i * 255 / (m * 2), 0));
		else if (pic->pnum == 3)
			return (color_rgb(i * 240 / m, i * 255 / m, (i * 128 / m) + 127));
	}
	return (0);
}
