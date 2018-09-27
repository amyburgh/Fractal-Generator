/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 21:59:35 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/10 23:04:10 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int		lerp(int start, int end, double p)
{
	if (start == end)
		return (start);
	return ((int)(double)start + (double)(end - start) * p);
}

static int		clerp(t_rgb c1, t_rgb c2, double p)
{
	t_rgb	c;

	if (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)
		return (rgb_to_hex(c1));
	c.r = (uint8_t)lerp((int)c1.r, (int)c2.r, p);
	c.g = (uint8_t)lerp((int)c1.g, (int)c2.g, p);
	c.b = (uint8_t)lerp((int)c1.b, (int)c2.b, p);
	return (rgb_to_hex(c));
}

static int		color_fractal(int i, t_view *v)
{
	t_hsv	hsv;

	if (v->season < 0)
	{
		hsv.h = 0.0;
		hsv.s = 0.0;
		hsv.v = (double)i / (double)v->imax;
	}
	else
	{
		hsv.h = (double)v->season + (double)i / (double)v->imax * RANGE;
		hsv.s = 1.0 - (double)i / (double)v->imax / 2.0;
		hsv.v = 1.0;
	}
	return (rgb_to_hex(hsv_to_rgb(hsv)));
}

static double	smooth_color(t_complex c, double i)
{
	double	n;
	double	zn;
	double	nu;

	zn = log(c.r * c.r + c.i * c.i) / 2.0;
	nu = log(zn / log(2.0)) / log(2.0);
	n = i + 1.0 - nu;
	return (n);
}

int				get_color(t_complex z, t_view *v, int i)
{
	int		c;
	int		c1;
	int		c2;
	double	n;

	n = fabs(smooth_color(z, i));
	c1 = color_fractal((int)n, v);
	c2 = color_fractal((int)n + 1.0, v);
	c = clerp(hex_to_rgb(c1), hex_to_rgb(c2), fmod(n, 1.0));
	return (c);
}
