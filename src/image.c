/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 19:13:08 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/10 22:44:08 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

void	pixel_put_image(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	*(int *)(img->data + (x + y * (img->size >> 2)) * img->bpp) = color;
}

void	clear_image(t_image *img)
{
	ft_bzero(img->data, WIN_X * WIN_Y * 4);
}

t_image	*del_image(t_mlx *root, t_image *img)
{
	if (img)
	{
		if (img->ptr)
			mlx_destroy_image(root->mlx, img->ptr);
		ft_memdel((void**)&img);
	}
	return (NULL);
}

t_image	*create_image(t_mlx *root)
{
	t_image	*img;

	if (!(img = (t_image*)ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->ptr = mlx_new_image(root->mlx, WIN_X, WIN_Y)))
		return (del_image(root, img));
	img->data = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size, &img->endian);
	img->bpp /= 8;
	return (img);
}
