/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:15:44 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/16 11:51:23 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fract_check_params(int argc, char **argv)
{
	int i;

	if (argc < 2 || argc > 3)
		fract_error_usage("usage: fractol [mandelbrot, julia, burning ship]\n");
	i = argc - 1;
	while (i > 0)
	{
		if (ft_strcmp("mandelbrot", argv[i]) != 0 &&
				ft_strcmp("julia", argv[i]) != 0 &&
				ft_strcmp("burning ship", argv[i]) != 0)
			fract_error_usage(
					"usage: fractol [mandelbrot, julia, burning ship]\n");
		i--;
	}
}

int		main(int argc, char **argv)
{
	t_win	*pic;

	fract_check_params(argc, argv);
	if (!(pic = (t_win *)malloc(sizeof(t_win))))
		fract_error_malloc();
	pic->win_w = WIN_W;
	pic->win_h = WIN_H;
	draw_win("42 Fractol", pic);
	init_fract(pic);
	init_palette(pic);
	fractal_change(argv[1], pic);
	mlx_expose_hook(pic->win, draw_reload, pic);
	mlx_mouse_hook(pic->win, mouse_hook, pic);
	mlx_hook(pic->win, EVENT_KEY_PRESS, EVENT_KEY_MASK, key_hook, pic);
	mlx_hook(pic->win, EVENT_MSEMOT_NOT, EVENT_MSEMOT_MASK, motion_hook, pic);
	mlx_loop(pic->mlx);
	return (0);
}
