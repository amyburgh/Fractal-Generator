/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:31:08 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/11 14:32:55 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include "libft.h"

t_rgb			hex_to_rgb(int hex)
{
	t_rgb	rgb;

	rgb.r = ((hex >> 16) & 0xFF);
	rgb.g = ((hex >> 8) & 0xFF);
	rgb.b = (hex & 0xFF);
	return (rgb);
}

int				rgb_to_hex(t_rgb rgb)
{
	return (((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff));
}

t_hsv			rgb_to_hsv(t_rgb rgb)
{
	t_hsv	hsv;
	double	delta;
	int		min;

	hsv = (t_hsv){.h = 0.0, .s = 0.0, .v = 0.0};
	min = MIN(MIN(rgb.r, rgb.g), rgb.b);
	hsv.v = MAX(MAX(rgb.r, rgb.g), rgb.b);
	delta = hsv.v - (double)min;
	if (hsv.v != 0.0)
		hsv.s = delta / hsv.v;
	if (hsv.s != 0.0)
	{
		if ((double)rgb.r == hsv.v)
			hsv.h = (rgb.g - rgb.b) / delta;
		else if ((double)rgb.g == hsv.v)
			hsv.h = 2 + (rgb.b - rgb.r) / delta;
		else if ((double)rgb.b == hsv.v)
			hsv.h = 4 + (rgb.r - rgb.g) / delta;
		hsv.h *= 60;
		if (hsv.h < 0.0)
			hsv.h += 360;
	}
	hsv.v /= 255.0;
	return (hsv);
}

static t_crgb	hsv_to_rgb2(t_hsv hsv)
{
	t_crgb	crgb;
	double	f;
	double	p;
	double	q;
	double	t;

	(hsv.h == 360.0) ? (hsv.h = 0.0) : (hsv.h /= 60.0);
	f = hsv.h - floor(hsv.h);
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v * (1.0 - (hsv.s * f));
	t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));
	if (0.0 <= hsv.h && hsv.h < 1.0)
		crgb = (t_crgb){.r = hsv.v, .g = t, .b = p};
	else if (1.0 <= hsv.h && hsv.h < 2.0)
		crgb = (t_crgb){.r = q, .g = hsv.v, .b = p};
	else if (2.0 <= hsv.h && hsv.h < 3.0)
		crgb = (t_crgb){.r = p, .g = hsv.v, .b = t};
	else if (3.0 <= hsv.h && hsv.h < 4.0)
		crgb = (t_crgb){.r = p, .g = q, .b = hsv.v};
	else if (4.0 <= hsv.h && hsv.h < 5.0)
		crgb = (t_crgb){.r = t, .g = p, .b = hsv.v};
	else if (5.0 <= hsv.h && hsv.h < 6.0)
		crgb = (t_crgb){.r = hsv.v, .g = p, .b = q};
	return (crgb);
}

t_rgb			hsv_to_rgb(t_hsv hsv)
{
	t_rgb	rgb;
	t_crgb	crgb;

	if (hsv.h > 360.0)
		hsv.h = (double)((int)hsv.h % 360);
	if (hsv.s == 0.0)
		crgb = (t_crgb){.r = hsv.v, .g = hsv.v, .b = hsv.v};
	else
		crgb = hsv_to_rgb2(hsv);
	rgb = (t_rgb){.r = crgb.r * 255, .g = crgb.g * 255, .b = crgb.b * 255};
	return (rgb);
}
