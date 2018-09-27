/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:20:20 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/11 14:49:18 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "mlx.h"
#include "libft.h"

void		error(int type)
{
	if (type == 1)
		ft_putendl("usage: ./fractol \033[31m[Fractol_Name] 💩\033[0m");
	if (type == 1 || type == 2)
	{
		ft_putendl("Available maps:");
		ft_putendl("\t\t\033[31m❄️  Mandelbrot  ❄️ \033[0m");
		ft_putendl("\t\t\033[33m❄️  Julia       ❄️ \033[0m");
		ft_putendl("\t\t\033[34m❄️  Burningship ❄️ \033[0m");
		ft_putendl("\t\t\033[35m❄️  Rabbit      ❄️ \033[0m");
		ft_putendl("\t\t\033[36m❄️  Tricorn     ❄️ \033[0m");
		ft_putendl("\t\t\033[37m❄️  Dragon      ❄️ \033[0m");
	}
	else if (type == 3)
		ft_putendl("error: \033[31m[Failed to initialize] 💩\033[0m");
	else if (type == 4)
		ft_putendl("error: \033[31m[Failed to create fractol image] 💩\033[0m");
	exit(1);
}

t_dispatch	*match_fractol(char *name)
{
	if (!ft_strcasecmp(MANDELBROT, name))
		return (&g_select[0]);
	else if (!ft_strcasecmp(JULIA, name))
		return (&g_select[1]);
	else if (!ft_strcasecmp(BURNINGSHIP, name))
		return (&g_select[2]);
	else if (!ft_strcasecmp(RABBIT, name))
		return (&g_select[3]);
	else if (!ft_strcasecmp(TRICORN, name))
		return (&g_select[4]);
	else if (!ft_strcasecmp(DRAGON, name))
		return (&g_select[5]);
	return (NULL);
}

int			main(int ac, char **av)
{
	t_mlx	root;

	if (ac != 2)
		error(1);
	if (!(root.fractol = match_fractol(av[1])))
		error(2);
	if (!(root.mlx = mlx_init()) || init_all(&root))
		error(3);
	if (!(root.win = mlx_new_window(root.mlx, WIN_X, WIN_Y, TITLE))
			|| !(root.img = create_image(&root)))
		error(4);
	render(&root);
	mlx_hook(root.win, 2, 0, key_press, &root);
	mlx_hook(root.win, 4, 0, mouse_press, &root);
	mlx_hook(root.win, 5, 0, mouse_release, &root);
	mlx_hook(root.win, 6, 0, mouse_motion, &root);
	mlx_hook(root.win, 17, 0, close_press, &root);
	mlx_loop(root.mlx);
	return (0);
}
