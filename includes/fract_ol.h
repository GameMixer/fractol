/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:10:13 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/16 18:00:43 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft.h"
# include "get_next_line.h"
# include "colors.h"
# include "keys.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <limits.h>

# define WIN_W 1920
# define WIN_H 1080

# define MOVE_DIST 10
# define ZOOM_AMOUNT 1.1

# define FRACTALS 3
# define PAL_SIZE 4

# define RANGE_CHECK(x, a, b, min, max) (((b)-(a))*((x)-(min))/((max)-(min)))+a

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_hsl
{
	int			h;
	double		s;
	double		l;
}				t_hsl;

typedef struct	s_palette
{
	int			color_0;
	int			color_1;
	int			color_2;
	int			color_3;
	int			color_4;
	int			color_5;
	int			color_6;
	int			color_7;
	int			color_8;
	int			color_9;
}				t_palette;

typedef struct	s_complex
{
	double		i;
	double		r;
}				t_complex;

typedef struct	s_fractal
{
	t_complex	c;
	t_complex	z;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		offx;
	double		offy;
	double		scale;
	double		tmp;
	int			iter;
	int			max;
	void		*func;
}				t_fract;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bits;
	int			size;
	int			endian;
	int			win_w;
	int			win_h;
	t_fract		*fract_ptr;
	t_fract		*fract_arr;
	t_palette	*palette;
	int			pnum;
}				t_win;

/*
**	Tools used for various things...like drawing.
**		util.c
*/
void			draw_win(char *title, t_win *pic);
int				draw_reload(t_win *pic);
void			adjust_fract(t_fract *fract, t_win *pic);
t_complex		num_to_complex(int x, int y, t_fract fract, t_win *pic);

/*
**	Initialize structures
**		init.c
*/
void			init_fract(t_win *pic);
void			init_palette(t_win *pic);

/*
**	Handles the fractal
**		fractal.c
*/
void			fractal_change(char *str, t_win *pic);
int				fractal_mandelbrot(t_win *pic, t_fract fract, t_point *point);
int				fractal_julia(t_win *pic, t_fract fract, t_point *point);
int				fractal_burn_ship(t_win *pic, t_fract fract, t_point *point);

/*
**	Draw the fractal
**		draw.c
*/
void			draw_fractal(t_win *pic, t_fract *fractal, int (*f)(t_win *,
					t_fract, t_point *));
void			draw_point(t_point *point, t_win *pic, int color);

/*
**	Its gotta be pretty. So color file!
**		color.c
*/
int				get_color(double i, int m, t_win *pic);
int				color_smooth(t_complex z, t_fract f, t_win *pic);
int				color_rgb(int r, int g, int b);

/*
**	Controls for the keyboard
**		key_hook.c
*/
int				key_hook(int keycode, t_win *pic);
void			key_hook_color(int keycode, t_win *pic);
void			key_hook_fractal(int keycode, t_win *pic);
void			key_hook_shift(int keycode, t_win *pic);
void			key_hook_scale(int keycode, t_win *pic);

/*
**	Controls for the mouse
**		mouse_hook.c
*/
int				mouse_hook(int button, int x, int y, t_win *pic);
int				motion_hook(int x, int y, t_win *pic);

/*
**	Error display
**		error.c
*/
void			fract_error_malloc(void);
void			fract_error_usage(char *str);

#endif
