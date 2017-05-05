/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:31:36 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/04 16:11:37 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	key_hook_scale(int keycode, t_win *pic)
{
	
}

void	key_hook_shift(int keycode, t_win *pic)
{
	if (keycode == KEY_UP)
	{
		
	}
	else if (keycode == KEY_DOWN)
	{
		
	}
	else if (keycode == KEY_LEFT)
	{
		
	}
	else if (keycode == KEY_RIGHT)
	{
		
	}
}

void	key_hook_fractal(int keycode, t_win *pic)
{
	if (keycode == KEY_KP_1)
		fractal_change("mandelbrot", pic);
	else if (keycode == KEY_KP_2)
		fractal_change("julia", pic);
	else if (keycode == KEY_KP_3)
		fractal_change("", pic);
}

void	key_hook_color(int keycode, t_win *pic)
{
	if (keycode == KEY_1)
		color_change(0, pic);
	else if (keycode == KEY_2)
		color_change(1, pic);
}

int		key_hook(int keycode, t_win *pic)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(pic->mlx, pic->win);
		exit (0);
	}
	key_hook_color(keycode, pic);
	key_hook_fractal(keycode, pic);
	key_hook_scale(keycode, pic);
	key_hook_shift(keycode, pic);
	draw_reload(pic);
	return (0);
}
