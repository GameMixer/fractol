/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:30:34 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/23 17:38:03 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		draw_win(char *title, t_win *pic)
{
	if (!(pic->mlx = mlx_init()))
		fract_error_mlx();
	pic->win = mlx_new_window(pic->mlx, pic->win_w, pic->win_h, title);
	if (!(pic->data = (int *)malloc(sizeof(int) * pic->win_w * pic->win_h)))
		fract_error_malloc();
}

int			draw_reload(t_win *pic)
{
	pic->img = mlx_new_image(pic->mlx, pic->win_w, pic->win_h);
	pic->img_addr = mlx_get_data_addr(pic->img, &(pic->bits),
			&(pic->size), &(pic->endian));
	draw_fractal(pic);
	mlx_put_image_to_window(pic->mlx, pic->win, pic->img, 0, 0);
	if (pic->help)
		display_info(pic);
	mlx_destroy_image(pic->mlx, pic->img);
	return (0);
}

void		adjust_fract(t_fract *fract, t_win *pic)
{
	double	w;
	double	h;

	w = fract->x2 - fract->x1;
	h = fract->y2 - fract->y1;
	if (w / h >= (float)pic->win_w / pic->win_h)
	{
		fract->y1 = -(w * pic->win_h / pic->win_w / 2);
		fract->y2 = w * pic->win_h / pic->win_w / 2;
	}
	else
	{
		fract->x1 = -(h * pic->win_w / pic->win_h / 2);
		fract->x2 = h * pic->win_w / pic->win_h / 2;
	}
}

void		zoom(int x, int y, t_win *pic, double s)
{
	double	w;
	double	h;
	double	nw;
	double	nh;

	w = (pic->fract_ptr->x2 - pic->fract_ptr->x1) * pic->fract_ptr->scale;
	h = (pic->fract_ptr->y2 - pic->fract_ptr->y1) * pic->fract_ptr->scale;
	pic->fract_ptr->scale *= s;
	nw = (pic->fract_ptr->x2 - pic->fract_ptr->x1) * pic->fract_ptr->scale;
	nh = (pic->fract_ptr->y2 - pic->fract_ptr->y1) * pic->fract_ptr->scale;
	pic->fract_ptr->offx -= ((double)x / pic->win_w) * (nw - w);
	pic->fract_ptr->offy -= ((double)y / pic->win_h) * (nh - h);
}

t_complex	num_to_complex(int x, int y, t_fract fract, t_win *pic)
{
	t_complex	p;

	p.r = (((double)x / pic->win_w) * (fract.x2 - fract.x1)) *
		fract.scale + fract.x1 + fract.offx;
	p.i = (((double)y / pic->win_h) * (fract.y2 - fract.y1)) *
		fract.scale + fract.y1 + fract.offy;
	return (p);
}
