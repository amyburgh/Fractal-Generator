/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:42:03 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/10 22:36:22 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void	zoom(int x, int y, t_view *v, double z)
{
	double dx;
	double dy;
	double new_dx;
	double new_dy;

	dx = (v->xmax - v->xmin);
	dy = (v->ymax - v->ymin);
	new_dx = (v->xmax - v->xmin) * z;
	new_dy = (v->ymax - v->ymin) * z;
	v->cx -= ((double)x / WIN_X) * (new_dx - dx) * v->zoom;
	v->cy -= ((double)y / WIN_Y) * (new_dy - dy) * v->zoom;
	v->zoom *= z;
}

int		key_press(int key, t_mlx *root)
{
	if (key == 53)
		exit(0);
	if (key == 49)
		root->menu ^= 1;
	if (key == 69)
		if (root->v->imax <= 128)
			root->v->imax *= 2;
	if (key == 78)
		if (root->v->imax > 4)
			root->v->imax /= 2;
	if (key == 76)
	{
		root->fractol->init(root->v);
		window_fit(root->v);
	}
	render(root);
	return (0);
}

int		close_press(t_mlx *root)
{
	(void)root;
	exit(0);
	return (0);
}
