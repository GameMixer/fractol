/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:31:36 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/25 14:23:30 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	key_hook_scale(int keycode, t_win *pic)
{
	if (keycode == KEY_KP_PLUS || keycode == KEY_EQUAL)
		zoom(pic->win_w / 2, pic->win_h / 2, pic, 1.0 / ZOOM_AMOUNT);
	else if (keycode == KEY_KP_MINUS || keycode == KEY_MINUS)
		zoom(pic->win_w / 2, pic->win_h / 2, pic, ZOOM_AMOUNT);
}

void	key_hook_shift(int keycode, t_win *pic)
{
	double	w;
	double	h;

	w = (pic->fract_ptr->x2 - pic->fract_ptr->x1) * pic->fract_ptr->scale;
	h = (pic->fract_ptr->y2 - pic->fract_ptr->y1) * pic->fract_ptr->scale;
	if (keycode == KEY_UP)
		pic->fract_ptr->offy -= h * MOVE_DIST;
	else if (keycode == KEY_DOWN)
		pic->fract_ptr->offy += h * MOVE_DIST;
	if (keycode == KEY_LEFT)
		pic->fract_ptr->offx -= w * MOVE_DIST;
	else if (keycode == KEY_RIGHT)
		pic->fract_ptr->offx += w * MOVE_DIST;
}

void	key_hook_fractal(int keycode, t_win *pic)
{
	if (keycode == KEY_KP_MULTI)
		pic->fract_ptr->max *= 2;
	else if (keycode == KEY_KP_DIV)
		if (pic->fract_ptr->max > 2)
			pic->fract_ptr->max /= 2;
}

void	key_hook_color(int keycode, t_win *pic)
{
	if (keycode == KEY_1)
		pic->pnum = 0;
	else if (keycode == KEY_2)
		pic->pnum = 1;
	else if (keycode == KEY_3)
		pic->pnum = 2;
	else if (keycode == KEY_4)
		pic->pnum = 3;
	else if (keycode == KEY_COMMA)
	{
		(pic->pnum)--;
		if (pic->pnum < 0)
			pic->pnum = PAL_SIZE - 1;
	}
	else if (keycode == KEY_PERIOD)
	{
		(pic->pnum)++;
		if (pic->pnum > PAL_SIZE - 1)
			pic->pnum = 0;
	}
}

int		key_hook(int keycode, t_win *pic)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(pic->mlx, pic->win);
		exit(0);
	}
	if (keycode == KEY_H)
		pic->help = 1 - pic->help;
	if (keycode == KEY_L)
		pic->lock = 1 - pic->lock;
	key_hook_color(keycode, pic);
	key_hook_fractal(keycode, pic);
	key_hook_scale(keycode, pic);
	key_hook_shift(keycode, pic);
	draw_reload(pic);
	return (0);
}
