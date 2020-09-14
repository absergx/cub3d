/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 15:59:02 by memilio           #+#    #+#             */
/*   Updated: 2020/09/10 17:04:11 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	wall_calc(t_all *all)
{
	all->ray.wall_height = (int)(all->params.r_xy[1] / all->ray.wall_dist);
	all->ray.wall_start = all->params.r_xy[1] / 2 - all->ray.wall_height / 2;
	if (all->ray.wall_start < 0)
		all->ray.wall_start = 0;
	all->ray.wall_end = all->ray.wall_height / 2 + all->params.r_xy[1] / 2;
	if (all->ray.wall_end >= all->params.r_xy[1])
		all->ray.wall_end = all->params.r_xy[1];
	if (all->ray.wall_side == 2 || all->ray.wall_side == 3)
		all->paint.wall_x = all->ray.player_y + all->ray.wall_dist
		* all->ray.r_d_y;
	else
		all->paint.wall_x = all->ray.player_x + all->ray.wall_dist
		* all->ray.r_d_x;
	all->paint.wall_x -= floor(all->paint.wall_x);
	all->paint.tex_x = (int)(all->paint.wall_x * (double)(all->paint.tex_w));
	if (all->ray.wall_side == 2 || all->ray.wall_side == 1)
		all->paint.tex_x = all->paint.tex_w - all->paint.tex_x - 1;
	all->paint.step = 1.0 * all->paint.tex_h / all->ray.wall_height;
	all->paint.tex_pos = (all->ray.wall_start - all->params.r_xy[1] / 2
		+ all->ray.wall_height / 2) * all->paint.step;
}

static void	check_rotation(t_all *all)
{
	if (all->ray.wall_side == 0)
	{
		all->paint.tex_h = all->tex.so_img.height;
		all->paint.tex_w = all->tex.so_img.width;
	}
	else if (all->ray.wall_side == 1)
	{
		all->paint.tex_h = all->tex.no_img.height;
		all->paint.tex_w = all->tex.no_img.width;
	}
	else if (all->ray.wall_side == 2)
	{
		all->paint.tex_h = all->tex.ea_img.height;
		all->paint.tex_w = all->tex.ea_img.width;
	}
	else if (all->ray.wall_side == 3)
	{
		all->paint.tex_h = all->tex.we_img.height;
		all->paint.tex_w = all->tex.we_img.width;
	}
	wall_calc(all);
}

int			get_color(t_data *img, int x, int y)
{
	int		color;

	color = 0;
	if (!img->width || !img->height)
		return (0);
	x = abs(x);
	y = abs(y);
	if ((x > img->width || y > img->height || x < 0 || y < 0))
		return (0);
	color = *(int *)(img->addr + ((x + (y * img->width))
		* (img->bits_per_pixel / 8)));
	return (color);
}

static void	paint_back(t_all *all, int x)
{
	int		y;

	y = 0;
	while (y < all->ray.wall_start)
	{
		my_mlx_pixel_put(&all->img, x, y, all->params.c_col);
		y++;
	}
	y = all->ray.wall_end;
	while (y < all->params.r_xy[1])
	{
		my_mlx_pixel_put(&all->img, x, y, all->params.f_col);
		y++;
	}
}

void		paint_magic(t_all *all, int x)
{
	int		color;
	int		y;

	check_rotation(all);
	paint_back(all, x);
	y = all->ray.wall_start;
	while (y < all->ray.wall_end)
	{
		all->paint.tex_y = (int)all->paint.tex_pos & (all->paint.tex_h - 1);
		if (all->ray.wall_side == 0)
			color = get_color(&all->tex.so_img, all->paint.tex_x,
				all->paint.tex_y);
		else if (all->ray.wall_side == 1)
			color = get_color(&all->tex.no_img, all->paint.tex_x,
				all->paint.tex_y);
		else if (all->ray.wall_side == 2)
			color = get_color(&all->tex.ea_img, all->paint.tex_x,
				all->paint.tex_y);
		else if (all->ray.wall_side == 3)
			color = get_color(&all->tex.we_img, all->paint.tex_x,
				all->paint.tex_y);
		all->paint.tex_pos += all->paint.step;
		my_mlx_pixel_put(&all->img, x, y, color);
		y++;
	}
}
