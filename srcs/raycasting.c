/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:46:44 by memilio           #+#    #+#             */
/*   Updated: 2020/09/10 17:04:59 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_field(char **map, int y, int x)
{
	if (map[y][x] == ' ' || map[y][x] == '0' || map[y][x] == '2'
	|| map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
		|| map[y][x] == 'E')
		return (1);
	return (0);
}

void		calc_start_dir(t_all *all)
{
	if (all->params.dir == 'N')
	{
		all->ray.d_y = -1;
		all->ray.plane_x = tan(M_PI * FOV / 360);
	}
	else if (all->params.dir == 'S')
	{
		all->ray.d_y = 1;
		all->ray.plane_x = -tan(M_PI * FOV / 360);
	}
	else if (all->params.dir == 'E')
	{
		all->ray.d_x = 1;
		all->ray.plane_y = tan(M_PI * FOV / 360);
	}
	else if (all->params.dir == 'W')
	{
		all->ray.d_x = -1;
		all->ray.plane_y = -tan(M_PI * FOV / 360);
	}
}

static void	calc_step(t_ray *ray)
{
	if (ray->r_d_x < 0)
	{
		ray->step_x = -1;
		ray->dist_x = (ray->player_x - ray->map_x) * ray->dlt_d_x;
	}
	else
	{
		ray->step_x = 1;
		ray->dist_x = (1.0 + ray->map_x - ray->player_x) * ray->dlt_d_x;
	}
	if (ray->r_d_y < 0)
	{
		ray->step_y = -1;
		ray->dist_y = (ray->player_y - ray->map_y) * ray->dlt_d_y;
	}
	else
	{
		ray->step_y = 1;
		ray->dist_y = (1.0 + ray->map_y - ray->player_y) * ray->dlt_d_y;
	}
}

static void	check_is_wall(t_all *all)
{
	all->ray.hit = 0;
	while (!all->ray.hit)
	{
		if (all->ray.dist_x < all->ray.dist_y)
		{
			all->ray.dist_x += all->ray.dlt_d_x;
			all->ray.map_x += all->ray.step_x;
			all->ray.wall_side = (all->ray.r_d_x < 0) ? 2 : 3;
		}
		else
		{
			all->ray.dist_y += all->ray.dlt_d_y;
			all->ray.map_y += all->ray.step_y;
			all->ray.wall_side = (all->ray.r_d_y < 0) ? 0 : 1;
		}
		if (!check_map_field(all->map.map, all->ray.map_y, all->ray.map_x))
			all->ray.hit = 1;
	}
	if (all->ray.wall_side > 1)
		all->ray.wall_dist = ((all->ray.map_x - all->ray.player_x +
			(1 - all->ray.step_x) / 2) / all->ray.r_d_x);
	else
		all->ray.wall_dist = ((all->ray.map_y - all->ray.player_y +
			(1 - all->ray.step_y) / 2) / all->ray.r_d_y);
}

void		raycasting(t_all *all)
{
	int		x;

	x = 0;
	while (x < all->params.r_xy[0])
	{
		all->ray.camera_x = 2 * x / (double)all->params.r_xy[0] - 1;
		all->ray.r_d_x = all->ray.d_x + all->ray.plane_x * all->ray.camera_x;
		all->ray.r_d_y = all->ray.d_y + all->ray.plane_y * all->ray.camera_x;
		if (!all->ray.r_d_y)
			all->ray.dlt_d_x = 0;
		else
			all->ray.dlt_d_x = (!all->ray.r_d_x) ? 1 : fabs(1 / all->ray.r_d_x);
		if (!all->ray.r_d_x)
			all->ray.dlt_d_y = 0;
		else
			all->ray.dlt_d_y = (!all->ray.r_d_y) ? 1 : fabs(1 / all->ray.r_d_y);
		all->ray.map_x = (int)all->ray.player_x;
		all->ray.map_y = (int)all->ray.player_y;
		calc_step(&all->ray);
		check_is_wall(all);
		paint_magic(all, x);
		all->ray.buffer[x++] = all->ray.wall_dist;
	}
	get_sprite(all);
}
