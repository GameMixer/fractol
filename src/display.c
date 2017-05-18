/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:39:53 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/18 13:38:42 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	display_controls(t_win *pic, int color)
{
	mlx_string_put(pic->mlx, pic->win, 10, 10, color,
			"============================CONTROLS============================");
	mlx_string_put(pic->mlx, pic->win, 10, 22, color,
			"Move View: Arrow Keys (UP, DOWN, LEFT, RIGHT)");
	mlx_string_put(pic->mlx, pic->win, 10, 46, color, "Zoom:");
	mlx_string_put(pic->mlx, pic->win, 70, 58, color,
			"IN: + on Keyboard or Left Click or Scroll Up on Mouse");
	mlx_string_put(pic->mlx, pic->win, 70, 70, color,
			"OUT: - on Keyboard or Right Click or Scroll Down on Mouse");
	mlx_string_put(pic->mlx, pic->win, 10, 94, color, "Change Themes:");
	mlx_string_put(pic->mlx, pic->win, 70, 106, color,
			"1: RGB, 2: Black and White, 3: Lava, 4: Winter");
	mlx_string_put(pic->mlx, pic->win, 70, 118, color, "PREV/NEXT: </>");
	mlx_string_put(pic->mlx, pic->win, 10, 142, color, "Change Iterations:");
	mlx_string_put(pic->mlx, pic->win, 70, 154, color,
			"Increase/Decrease: Keypad * / Keypad /");
	mlx_string_put(pic->mlx, pic->win, 10, 178, color,
			"Toggle Mouse Lock (For julia fractal): L");
	mlx_string_put(pic->mlx, pic->win, 10, 190, color,
			"Toggle help (These words up here): H");
	mlx_string_put(pic->mlx, pic->win, 10, 202, color,
			"===========================ESC to Quit==========================");
/*	return ("===========================CONTROLS===========================\n\
			Move View:\n\
			    Arror Keys: UP, DOWN, LEFT, RIGHT\n\n \
			Zoom:\n\
			    IN:  + or Left Click or Scroll Up\n\
			    OUT: - or Right Clcik or Scroll Down\n\n\
			Change Iteration Amount:\n\
			    Increase: Keypad *\n\
			    Decrease: Keypad /\n\n\
			Change Themes:\n\
			    1: RGB, 2: Black and White, 3: Lava, 4: Winter\n\
			    NEXT: >\n\
				PREV: <\n\n\
			Change Fractals:\n\
			    Keypad 1: Mandelbrot, Keypad 2: Julia, Keypad 3: Burning ship\n\
			\nToggle Mouse Lock (For julia): L\
			\nToggle Help: H\
			==========================ESC to Quit=========================");*/
}

char	*display_theme(t_win *pic)
{
	if (pic->pnum == 0)
		return ("RGB");
	if (pic->pnum == 1)
		return ("Black and White");
	if (pic->pnum == 2)
		return ("Lava");
	return ("Winter");
}

char	*display_fractal(t_win *pic)
{
	if (pic->fract_ptr == &(pic->fract_arr[0]))
		return ("mandelbrot");
	if (pic->fract_ptr == &(pic->fract_arr[1]))
		return ("julia");
	return ("burning boat");
}

void	display_info(t_win *pic)
{
	int	color;

	color = get_color((double)pic->fract_ptr->max, pic->fract_ptr->max, pic);
	display_controls(pic, color);
	mlx_string_put(pic->mlx, pic->win, 10, pic->win_h - 22, color,
			"Iterations: ");
	mlx_string_put(pic->mlx, pic->win, 154, pic->win_h - 22, color,
			ft_itoa(pic->fract_ptr->max));
	mlx_string_put(pic->mlx, pic->win, 10, pic->win_h - 34, color,
			"Theme:      ");
	mlx_string_put(pic->mlx, pic->win, 154, pic->win_h - 34, color,
			display_theme(pic));
	mlx_string_put(pic->mlx, pic->win, 10, pic->win_h - 46, color,
			"Fractal:    ");
	mlx_string_put(pic->mlx, pic->win, 154, pic->win_h - 46, color,
			display_fractal(pic));
	mlx_string_put(pic->mlx, pic->win, 10, pic->win_h - 58, color,
			"Mouse Lock: ");
	if (pic->lock)
		mlx_string_put(pic->mlx, pic->win, 154, pic->win_h - 58, color, "ON");
	else
		mlx_string_put(pic->mlx, pic->win, 154, pic->win_h - 58, color, "OFF");
}
