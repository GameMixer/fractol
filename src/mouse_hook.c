/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:14:51 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/04 17:32:02 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		motion_hook(int x, int y, t_win *pic)
{
	if (x >= 0 && y >= 0 && x <= pic->win_w && y <= pic->win_h)
	{
		pic->fract_ptr->c
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_win *pic)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_CLICK_L ||
			button == MOUSE_SCROLL_DOWN || button == MOUSE_CLICK_R)
	{
		pic->fract_ptr->x1 += (((double)x - pic->win_h / 2) / pic->win_w / 2);
		pic->fract_ptr->x2 += (((double)x - pic->win_h / 2) / pic->win_w / 2);
		pic->fract_ptr->y1 += (((double)y - pic->win_w / 2) / pic->win_h / 2);
		pic->fract_ptr->y2 += (((double)y - pic->win_w / 2) / pic->win_h / 2);
	}
	if (button == MOUSE_SCROLL_UP || button == MOUSE_CLICK_L)
	{
		
	}
	else if (button == MOUSE_SCROLL_DOWN || button == MOUSE_CLICK_R)
	{
		
	}
	draw_reload(pic);
	return (0);
}
