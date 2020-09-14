/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:11:04 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 15:44:39 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		press_key(int key, t_all *all)
{
	if (key == ESC)
		close_win(all);
	else if (key == W)
		all->keys.w = 1;
	else if (key == A)
		all->keys.a = 1;
	else if (key == D)
		all->keys.d = 1;
	else if (key == S)
		all->keys.s = 1;
	else if (key == LEFT)
		all->keys.left = 1;
	else if (key == RIGHT)
		all->keys.right = 1;
	return (0);
}

static int		release_key(int key, t_all *all)
{
	if (key == W)
		all->keys.w = 0;
	else if (key == A)
		all->keys.a = 0;
	else if (key == D)
		all->keys.d = 0;
	else if (key == S)
		all->keys.s = 0;
	else if (key == LEFT)
		all->keys.left = 0;
	else if (key == RIGHT)
		all->keys.right = 0;
	return (0);
}

static void		processing_keys(t_all *all)
{
	if (all->keys.w)
		press_w(all);
	if (all->keys.a)
		press_a(all);
	if (all->keys.s)
		press_s(all);
	if (all->keys.d)
		press_d(all);
	if (all->keys.left || all->keys.right)
		press_l_r(all);
}

static int		control_keys(t_all *all)
{
	processing_keys(all);
	mlx_destroy_image(all->mlx, all->img.img);
	if (!(all->img.img = mlx_new_image(all->mlx, all->params.r_xy[0],
		all->params.r_xy[1])))
		free_all(all, -14);
	if (!(all->img.addr = mlx_get_data_addr(all->img.img,
		&all->img.bits_per_pixel, &all->img.line_length, &all->img.endian)))
		free_all(all, -14);
	raycasting(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	return (0);
}

void			hook_button(t_all *all)
{
	mlx_hook(all->win, 2, 1L << 0, &press_key, all);
	mlx_hook(all->win, 3, 1L << 1, &release_key, all);
	mlx_hook(all->win, 17, 1L << 17, &close_win, all);
	mlx_loop_hook(all->mlx, &control_keys, all);
}
