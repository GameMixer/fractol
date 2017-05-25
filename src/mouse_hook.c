/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:14:51 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/23 13:16:55 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		motion_hook(int x, int y, t_win *pic)
{
	if (x >= 0 && y >= 0 && x <= pic->win_w && y <= pic->win_h)
	{
		if (!(pic->lock))
		{
			pic->fract_ptr->c.r = (double)x / (double)pic->win_w * 4 - 2;
			pic->fract_ptr->c.i = (double)y / (double)pic->win_h * 4 - 2;
		}
		draw_reload(pic);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_win *pic)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_CLICK_L)
	{
		zoom(x, y, pic, 1.0 / ZOOM_AMOUNT);
		draw_reload(pic);
	}
	else if (button == MOUSE_SCROLL_DOWN || button == MOUSE_CLICK_R)
	{
		zoom(x, y, pic, ZOOM_AMOUNT);
		draw_reload(pic);
	}
	return (0);
}
