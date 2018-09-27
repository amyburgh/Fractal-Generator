/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 20:51:06 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/10 22:29:41 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <pthread.h>
#include "fractol.h"
#include "mlx.h"

t_complex	scale_values(int x, int y, t_view *v)
{
	t_complex	p;
	double		dx;
	double		dy;

	dx = (double)v->xmax - v->xmin;
	dy = (double)v->ymax - v->ymin;
	p.r = (double)x / (double)WIN_X * dx * v->zoom + v->xmin + v->cx;
	p.i = (double)y / (double)WIN_Y * dy * v->zoom + v->ymin + v->cy;
	return (p);
}

void		window_fit(t_view *v)
{
	double	dx;
	double	dy;

	dx = (v->xmax - v->xmin);
	dy = (v->ymax - v->ymin);
	if (dx / dy <= (double)WIN_X / WIN_Y)
	{
		v->xmin = -dy * WIN_X / WIN_Y / 2;
		v->xmax = dy * WIN_X / WIN_Y / 2;
	}
	else
	{
		v->ymin = -dx * WIN_Y / WIN_X / 2;
		v->ymax = dx * WIN_Y / WIN_X / 2;
	}
}

void		*draw_fractol(void *param)
{
	int		x;
	int		y;
	int		color;
	t_argp	*argp;
	int		i;

	i = 0;
	argp = (t_argp *)param;
	y = argp->id;
	while (i < (WIN_Y / THREADS))
	{
		x = 0;
		while (x < WIN_X)
		{
			color = argp->root->fractol->fractal(x, y, argp->root,
					argp->root->v);
			pixel_put_image(argp->root->img, x, y, color);
			x++;
		}
		y += THREADS;
		i++;
	}
	pthread_exit(0);
}

int			render(t_mlx *root)
{
	int			i;
	pthread_t	id[THREADS];
	t_argp		argp[THREADS];

	i = -1;
	clear_image(root->img);
	while (++i < THREADS)
	{
		argp[i] = (t_argp){.id = i, .root = root};
		pthread_create(&id[i], NULL, draw_fractol, &argp[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(id[i], NULL);
	mlx_put_image_to_window(root->mlx, root->win, root->img->ptr, 0, 0);
	if (root->menu & 1)
	{
		mlx_put_image_to_window(root->mlx, root->win,
				root->palette->ptr, 0,
				(WIN_Y - root->palette->height) / 2);
		mlx_put_image_to_window(root->mlx, root->win,
				root->fractals->ptr, WIN_X - root->fractals->width,
				(WIN_Y - root->fractals->height) / 2);
	}
	return (0);
}
