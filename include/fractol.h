/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 19:36:50 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/11 14:37:19 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>

# define TITLE "Fract'ol"
# define WIN_X 1920
# define WIN_Y 1080
# define IMAX 32
# define ZOOM 1.1
# define THREADS 8

# define JULIA "julia"
# define MANDELBROT "mandelbrot"
# define BURNINGSHIP "burningship"
# define RABBIT "rabbit"
# define TRICORN "tricorn"
# define DRAGON "dragon"

# define RANGE 270.0
# define SPRING 0
# define SUMMER 45
# define FALL 180
# define WINTER 270
# define GREYSCALE -1

typedef struct		s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}					t_rgb;

typedef	struct		s_crgb
{
	double	r;
	double	g;
	double	b;
}					t_crgb;

typedef struct		s_hsv
{
	double	h;
	double	s;
	double	v;
}					t_hsv;

typedef struct		s_complex
{
	double	r;
	double	i;
}					t_complex;

typedef struct		s_xpm
{
	void	*ptr;
	int		width;
	int		height;
}					t_xpm;

typedef struct		s_image
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		size;
	int		endian;
}					t_image;

typedef struct		s_mouse
{
	uint8_t	active;
	int		x;
	int		y;
	int		oldx;
	int		oldy;
}					t_mouse;

typedef struct		s_view
{
	double	xmin;
	double	ymin;
	double	xmax;
	double	ymax;
	double	cx;
	double	cy;
	double	zoom;
	int		imax;
	int		season;
}					t_view;

typedef	struct s_mlx	t_mlx;

typedef int			(*t_frac)(int, int, t_mlx*, t_view*);

typedef void		(*t_init)(t_view*);

typedef struct		s_dispatch
{
	char	*name;
	t_init	init;
	t_frac	fractal;
}					t_dispatch;

extern	t_dispatch	g_select[];

typedef	struct		s_argp
{
	int				id;
	t_mlx			*root;
}					t_argp;

struct				s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_mouse		*mouse;
	t_view		*v;
	t_xpm		*palette;
	t_xpm		*fractals;
	uint8_t		menu:1;
	t_dispatch	*fractol;
};
/*
** --- init.c ---
*/
int					init_all(t_mlx *root);
/*
** --- render.c ---
*/
t_complex			scale_values(int x, int y, t_view *v);
void				window_fit(t_view *v);
int					render(t_mlx *root);
/*
** --- image.c ---
*/
void				pixel_put_image(t_image *img, int x, int y, int color);
t_image				*create_image(t_mlx *root);
t_image				*del_image(t_mlx *root, t_image *img);
void				clear_image(t_image *img);

/*
** --- mouse_hooks.c ---
*/
int					mouse_press(int button, int x, int y, t_mlx *root);
int					mouse_release(int button, int x, int y, t_mlx *root);
int					mouse_motion(int x, int y, t_mlx *root);
/*
** --- key_hooks.c ---
*/
void				zoom(int x, int y, t_view *v, double z);
int					key_press(int key, t_mlx *root);
int					close_press(t_mlx *root);
/*
** --- colors.c ---
*/
t_rgb				hex_to_rgb(int hex);
int					rgb_to_hex(t_rgb rgb);
t_hsv				rgb_to_hsv(t_rgb rgb);
t_rgb				hsv_to_rgb(t_hsv hsv);
/*
** --- smooth_colors.c ---
*/
int					get_color(t_complex z, t_view *v, int i);
/*
** --- mj_fractals.c ---
*/
void				init_mandelbrot(t_view *v);
int					mandelbrot_set(int x, int y, t_mlx *root, t_view *v);
void				init_julia(t_view *v);
int					julia_set(int x, int y, t_mlx *root, t_view *v);
/*
** --- br_fractals.c ---
*/
void				init_burningship(t_view *v);
int					burningship_set(int x, int y, t_mlx *root, t_view *v);
void				init_rabbit(t_view *v);
int					rabbit_set(int x, int y, t_mlx *root, t_view *v);
/*
** --- td_fractals.c ---
*/
void				init_tricorn(t_view *v);
int					tricorn_set(int x, int y, t_mlx *root, t_view *v);
void				init_dragon(t_view *v);
int					dragon_set(int x, int y, t_mlx *root, t_view *v);

#endif
