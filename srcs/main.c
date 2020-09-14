/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 11:46:21 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 15:49:09 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void		validate_screen_size(t_all *all)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_get_screen_size(all->mlx, &x, &y);
	if (all->params.r_xy[0] > x)
		all->params.r_xy[0] = x;
	if (all->params.r_xy[1] > y)
		all->params.r_xy[1] = y;
}

static void		activate_mlx(t_all *all)
{
	all->mlx = mlx_init();
	validate_screen_size(all);
	if (!(all->ray.buffer = (double*)malloc(sizeof(double)
		* all->params.r_xy[0])))
		free_all(all, -1);
	if (!(all->win = mlx_new_window(all->mlx, all->params.r_xy[0],
		all->params.r_xy[1], "Cub3d")))
		free_all(all, -14);
	if (!(all->img.img = mlx_new_image(all->mlx, all->params.r_xy[0],
		all->params.r_xy[1])))
		free_all(all, -14);
	if (!(all->img.addr = mlx_get_data_addr(all->img.img,
		&all->img.bits_per_pixel, &all->img.line_length, &all->img.endian)))
		free_all(all, -14);
}

int				main(int argc, char **argv)
{
	t_all		all;

	init(&all);
	if (!total_validate(&all, argc, argv))
		return (0);
	activate_mlx(&all);
	if (!load_textures(&all))
		free_all(&all, -2);
	calc_start_dir(&all);
	raycasting(&all);
	if (all.screenshot)
		shot_screen(&all);
	mlx_put_image_to_window(all.mlx, all.win, all.img.img, 0, 0);
	hook_button(&all);
	mlx_loop(all.mlx);
	return (0);
}
