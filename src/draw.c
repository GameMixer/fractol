/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:14:32 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/18 11:18:48 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <pthread.h>

void	*draw_thread(void *p)
{
	t_thread	*t;
	t_point		point;
	int			(*f)(t_win *, t_fract, t_point *);

	t = (t_thread *)p;
	f = t->pic->fract_ptr->func;
	point.y = WIN_H / THREADS * t->id;
	while (point.y < WIN_H / THREADS * (t->id + 1))
	{
		point.x = 0;
		while (point.x < WIN_W)
		{
			*(t->pic->data + (int)point.y * WIN_W + (int)point.x) =
				(*f)(t->pic, *(t->pic->fract_ptr), &point);
			(point.x)++;
		}
		(point.y)++;
	}
	return (NULL);
}

void	draw_render(t_win *pic)
{
	int			i;
	t_render	*r;

	i = 0;
	r = &pic->render;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].pic = pic;
		pthread_create(r->threads + i, NULL, draw_thread, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
}

void	draw_fractal(t_win *pic/*, t_fract *fractal,
		int (*f)(t_win *, t_fract, t_point *)*/)
{
	t_point	point;
	//int		color;

	draw_render(pic);
	point.y = 0;
	while (point.y < pic->win_h)
	{
		point.x = 0;
		while (point.x < pic->win_w)
		{
			//color = (*f)(pic, *fractal, &point);
			draw_point(&(point), pic,
					*(pic->data + (int)point.y * pic->win_w + (int)point.x));
			(point.x)++;
		}
		(point.y)++;
	}
}

void	draw_point(t_point *point, t_win *pic, int color)
{
	if (!(point->x < 0 || point->x >= pic->win_w ||
				point->y < 0 || point->y >= pic->win_h))
	{
		ft_memcpy(&(pic->img_addr[((int)(point->x) * 4) +
					((int)(point->y) * pic->size)]),
				&(color), (size_t)(sizeof(int)));
	}
}
