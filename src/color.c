/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:53:36 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/09 17:53:29 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		color_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + ((b & 0xFF)));
}

int		find_color(int z, int c1, int c2, double min)
{
	int		t1;
	int		t2;
	double	max;
	int		color;

	if (z <= min)
		return (c1);
	max = min + 11;
	if (z >= max)
		return (c2);
	t1 = c1 / 256 / 256;
	t2 = c2 / 256 / 256;
	color = ((((z - fabs(min)) * (t2 - t1)) /
				(max - fabs(min))) + t1) * 256 * 256;
	t1 = c1 / 256 % 256;
	t2 = c2 / 256 % 256;
	color += ((((z - fabs(min)) * (t2 - t1)) / (max - fabs(min))) + t1) * 256;
	t1 = c1 % 256;
	t2 = c2 % 256;
	color += ((((z - fabs(min)) * (t2 - t1)) / (max - fabs(min))) + t1);
	return (color);
}

int		get_color(int z, t_palette palette)
{
	int color;

	z = sin(z) * 100;
	if (z < 0)
		color = palette.color_0;
	else if (z >= 0 && z < 11)
		color = find_color(z, palette.color_1, palette.color_2, 0);
	else if (z >= 11 && z < 22)
		color = find_color(z, palette.color_2, palette.color_3, 11);
	else if (z >= 22 && z < 33)
		color = find_color(z, palette.color_3, palette.color_4, 22);
	else if (z >= 33 && z < 44)
		color = find_color(z, palette.color_4, palette.color_5, 33);
	else if (z >= 44 && z < 55)
		color = find_color(z, palette.color_5, palette.color_6, 44);
	else if (z >= 55 && z < 66)
		color = find_color(z, palette.color_6, palette.color_7, 55);
	else if (z >= 66 && z < 77)
		color = find_color(z, palette.color_7, palette.color_8, 66);
	else if (z >= 77 && z < 88)
		color = find_color(z, palette.color_8, palette.color_9, 77);
	else
		color = palette.color_9;
	return (color);
}
/*
void	color_change(int num, t_win *pic)
{
	if (num >= 0 && num < PAL_SIZE)
		pic->pal_ptr = &(pic->palette[num]);
	else if (num < 0)
		pic->pal_ptr = &(pic->palette[PAL_SIZE - 1]);
	else
		pic->pal_ptr = &(pic->palette[0]);
}
*/
