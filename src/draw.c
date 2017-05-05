/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:14:32 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/04 15:29:47 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_fractal(t_win *pic, t_fract *fractal,
		int (*f)(t_win *, t_fract, t_point *))
{
	t_point	point;
	int		color;

	point.y = 0;
	while (point.y < pic->win_h)
	{
		point.x = 0;
		while (point.x < pic<win_w)
		{
			color = (*f)(pic, *fractal, &point);
			draw_point(&(point), pic, color);
			(point.x)++;
		}
		(point.y)++;
	}
}

void	draw_point(t_point *point, t_win *pic, int color)
{
	ft_memcpy(&(pic->img_addr[((int)(point->x) * 4) +
				((int)(point->y) * pic->size)]),
			&(color), (size_t)(sizeof(int)));
}
