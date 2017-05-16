/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:30:34 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/08 18:44:17 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_win(char *title, t_win *pic)
{
	if (!(pic->mlx = mlx_init()))
		fract_error_usage("error mlx init.\n");
	pic->win = mlx_new_window(pic->mlx, pic->win_w, pic->win_h, title);
}

int		draw_reload(t_win *pic)
{
	pic->img = mlx_new_image(pic->mlx, pic->win_w, pic->win_h);
	pic->img_addr = mlx_get_data_addr(pic->img, &(pic->bits),
			&(pic->size), &(pic->endian));
	draw_fractal(pic, pic->fract_ptr, pic->fract_ptr->func);
	mlx_put_image_to_window(pic->mlx, pic->win, pic->img, 0, 0);
	mlx_destroy_image(pic->mlx, pic->img);
	return (0);
}
