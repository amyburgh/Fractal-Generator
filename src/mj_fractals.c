/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mj_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 22:07:30 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/10 22:20:55 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	init_mandelbrot(t_view *v)
{
	v->xmin = -2.5;
	v->xmax = 1.0;
	v->ymin = -1.0;
	v->ymax = 1.0;
	v->cx = -0.5;
	v->cy = 0.0;
	v->zoom = 1.0;
	v->imax = 64;
	v->season = 0;
}

int		mandelbrot_set(int x0, int y0, t_mlx *root, t_view *v)
{
	int			i;
	t_complex	z;
	t_complex	z2;
	t_complex	c;

	i = 0;
	(void)root;
	z = (t_complex){.r = 0.0, .i = 0.0};
	z2 = (t_complex){.r = 0.0, .i = 0.0};
	c = scale_values(x0, y0, v);
	while (z2.r + z2.i < 4.0 && i < v->imax)
	{
		z2.r = z.r * z.r;
		z2.i = z.i * z.i;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = z2.r - z2.i + c.r;
		i++;
	}
	if (z2.r + z2.i > 4.0)
		return (get_color(z, v, i));
	return (0);
}

void	init_julia(t_view *v)
{
	v->xmin = -2.5;
	v->xmax = 1.0;
	v->ymin = -1.0;
	v->ymax = 1.0;
	v->cx = 0.0;
	v->cy = 0.0;
	v->zoom = 1.0;
	v->imax = IMAX;
	v->season = WINTER;
}

int		julia_set(int x, int y, t_mlx *root, t_view *v)
{
	t_complex	z;
	t_complex	z2;
	t_complex	c;
	int			i;

	i = 0;
	z = scale_values(x, y, v);
	z2 = (t_complex){.r = 0.0, .i = 0.0};
	c = scale_values(root->mouse->x, root->mouse->y, v);
	while (z2.r + z2.i < 4.0 && i < v->imax)
	{
		z2.r = z.r * z.r;
		z2.i = z.i * z.i;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = z2.r - z2.i + c.r;
		i++;
	}
	if (z2.r + z2.i > 4.0)
		return (get_color(z, v, i));
	return (0);
}
