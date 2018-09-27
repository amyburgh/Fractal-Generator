/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:40:39 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/11 14:39:04 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_season(int x, int y, t_mlx *root)
{
	if (y >= 280 && y < 380)
		root->v->season = SPRING;
	else if (y >= 380 && y < 485)
		root->v->season = SUMMER;
	else if (y >= 485 && y < 590)
		root->v->season = FALL;
	else if (y >= 590 && y < 695)
		root->v->season = WINTER;
	else if (y >= 695 && y < 800)
		root->v->season = GREYSCALE;
}

static void	change_fractal(int x, int y, t_mlx *root)
{
	if (y >= 200 && y < 325)
		root->fractol = &g_select[0];
	else if (y >= 325 && y < 450)
		root->fractol = &g_select[1];
	else if (y >= 450 && y < 550)
		root->fractol = &g_select[2];
	else if (y >= 550 && y < 650)
		root->fractol = &g_select[3];
	else if (y >= 650 && y < 750)
		root->fractol = &g_select[4];
	else if (y >= 750 && y < 875)
		root->fractol = &g_select[5];
	root->fractol->init(root->v);
	window_fit(root->v);
}

int			mouse_press(int button, int x, int y, t_mlx *root)
{
	root->mouse->active |= 1 << button;
	if (button == 4)
		zoom(x, y, root->v, ZOOM);
	else if (button == 5)
		zoom(x, y, root->v, 1 / ZOOM);
	if (root->menu & 1 && root->mouse->active & (1 << 1))
	{
		if (x >= 20 && x < 140)
			change_season(x, y, root);
		else if (x >= 1780 && x < WIN_X - 20)
			change_fractal(x, y, root);
	}
	render(root);
	return (0);
}

int			mouse_release(int button, int x, int y, t_mlx *root)
{
	(void)x;
	(void)y;
	root->mouse->active &= ~(1 << button);
	return (0);
}

int			mouse_motion(int x, int y, t_mlx *root)
{
	double	dx;
	double	dy;

	root->mouse->oldx = root->mouse->x;
	root->mouse->oldy = root->mouse->y;
	root->mouse->x = x;
	root->mouse->y = y;
	if (root->mouse->active & (1 << 1))
	{
		dx = (root->v->xmax - root->v->xmin) * root->v->zoom;
		dy = (root->v->ymax - root->v->ymin) * root->v->zoom;
		root->v->cx += (double)(root->mouse->oldx - root->mouse->x)
			/ WIN_X * dx;
		root->v->cy += (double)(root->mouse->oldy - root->mouse->y)
			/ WIN_Y * dy;
	}
	render(root);
	return (0);
}
