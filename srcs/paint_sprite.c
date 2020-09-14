/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:21:30 by memilio           #+#    #+#             */
/*   Updated: 2020/09/10 17:04:04 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_sprite(t_all *all, int stripe)
{
	int		y;
	int		d;
	int		color;

	y = all->sp_p.draw_start_y;
	while (y < all->sp_p.draw_end_y)
	{
		d = y * 256 - all->params.r_xy[1] * 128 + all->sp_p.sprite_h * 128;
		all->sp_p.tex_y = ((d * all->tex.s_img.height) / all->sp_p.sprite_h)
			/ 256;
		color = get_color(&all->tex.s_img, all->sp_p.tex_x, all->sp_p.tex_y);
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&all->img, stripe, y, color);
		y++;
	}
}

static void	draw_sprite(t_all *all)
{
	int		stripe;

	stripe = all->sp_p.draw_start_x;
	while (stripe < all->sp_p.draw_end_x)
	{
		all->sp_p.tex_x = (int)(256 * (stripe - (-all->sp_p.sprite_w / 2
		+ all->sp_p.sprite_screen_x)) * all->tex.s_img.width
		/ all->sp_p.sprite_w) / 256;
		if (all->sp_p.transform_y > 0 && stripe >= 0 && stripe <
		all->params.r_xy[0] && all->sp_p.transform_y < all->ray.buffer[stripe])
			put_sprite(all, stripe);
		stripe++;
	}
}

static void	calc_sprite_s_e(t_all *all)
{
	all->sp_p.draw_start_y = -all->sp_p.sprite_h / 2 + all->params.r_xy[1]
		/ 2;
	if (all->sp_p.draw_start_y < 0)
		all->sp_p.draw_start_y = 0;
	all->sp_p.draw_end_y = all->sp_p.sprite_h / 2 + all->params.r_xy[1]
		/ 2;
	if (all->sp_p.draw_end_y >= all->params.r_xy[1])
		all->sp_p.draw_end_y = all->params.r_xy[1];
	all->sp_p.draw_start_x = -all->sp_p.sprite_w / 2
		+ all->sp_p.sprite_screen_x;
	if (all->sp_p.draw_start_x < 0)
		all->sp_p.draw_start_x = 0;
	all->sp_p.draw_end_x = all->sp_p.sprite_w / 2 + all->sp_p.sprite_screen_x;
	if (all->sp_p.draw_end_x >= all->params.r_xy[0])
		all->sp_p.draw_end_x = all->params.r_xy[0];
	draw_sprite(all);
}

void		paint_sprite(t_all *all, t_sprite *sprite)
{
	all->sp_p.sprite_x = sprite->x - all->ray.player_x;
	all->sp_p.sprite_y = sprite->y - all->ray.player_y;
	all->sp_p.invdet = 1.0 / (all->ray.plane_x * all->ray.d_y - all->ray.d_x
		* all->ray.plane_y);
	all->sp_p.transform_x = all->sp_p.invdet * (all->ray.d_y
		* all->sp_p.sprite_x - all->ray.d_x * all->sp_p.sprite_y);
	all->sp_p.transform_y = all->sp_p.invdet * (-all->ray.plane_y
		* all->sp_p.sprite_x + all->ray.plane_x * all->sp_p.sprite_y);
	all->sp_p.sprite_screen_x = (int)((all->params.r_xy[0] / 2) * (1
		+ all->sp_p.transform_x / all->sp_p.transform_y));
	all->sp_p.sprite_h = abs((int)((all->params.r_xy[1]
		/ all->sp_p.transform_y)));
	all->sp_p.sprite_w = abs((int)((all->params.r_xy[1]
		/ all->sp_p.transform_y)));
	calc_sprite_s_e(all);
}
