/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 20:29:09 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/11 00:23:11 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

t_dispatch	g_select[] = {
	{"mandelbrot", &init_mandelbrot, &mandelbrot_set},
	{"julia", &init_julia, &julia_set},
	{"burningship", &init_burningship, &burningship_set},
	{"rabbit", &init_rabbit, &rabbit_set},
	{"tricorn", &init_tricorn, &tricorn_set},
	{"dragon", &init_dragon, &dragon_set}
};

void		init_mouse(t_mouse *mouse)
{
	mouse->active = 0x00;
	mouse->x = WIN_X >> 1;
	mouse->y = WIN_Y >> 1;
	mouse->oldx = WIN_X >> 1;
	mouse->oldy = WIN_Y >> 1;
}

int			init_all(t_mlx *root)
{
	t_mouse *mouse;
	t_view	*v;
	t_xpm	*palette;
	t_xpm	*fractals;

	ERROR_CHECK(!(v = ft_memalloc(sizeof(t_view))));
	ERROR_CHECK(!(mouse = ft_memalloc(sizeof(t_mouse))));
	ERROR_CHECK(!(palette = ft_memalloc(sizeof(t_xpm))));
	ERROR_CHECK(!(fractals = ft_memalloc(sizeof(t_xpm))));
	palette->ptr = mlx_xpm_file_to_image(root->mlx, "images/palette.xpm",
			&palette->width, &palette->height);
	fractals->ptr = mlx_xpm_file_to_image(root->mlx, "images/fractals.xpm",
			&fractals->width, &fractals->height);
	init_mouse(mouse);
	root->fractol->init(v);
	window_fit(v);
	root->mouse = mouse;
	root->palette = palette;
	root->fractals = fractals;
	root->menu = 1;
	root->v = v;
	return (0);
}
