/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:32:19 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 13:15:25 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->r_d_x = 0;
	ray->r_d_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0;
	ray->dist_x = 0;
	ray->dist_y = 0;
	ray->player_x = 0;
	ray->player_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->d_x = 0;
	ray->d_y = 0;
	ray->dlt_d_x = 0;
	ray->dlt_d_y = 0;
	ray->hit = 0;
	ray->wall_side = 0;
	ray->wall_dist = 0;
	ray->wall_start = 0;
	ray->wall_height = 0;
	ray->wall_end = 0;
	ray->buffer = NULL;
}

static void	init_params(t_params *params)
{
	params->r = 0;
	params->r_xy[0] = 0;
	params->r_xy[1] = 0;
	params->no = 0;
	params->no_path = NULL;
	params->so = 0;
	params->so_path = NULL;
	params->we = 0;
	params->we_path = NULL;
	params->ea = 0;
	params->ea_path = NULL;
	params->s = 0;
	params->s_path = NULL;
	params->f = 0;
	params->f_col = 0;
	params->c = 0;
	params->c_col = 0;
	params->dir = 0;
}

static void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}

static void	init_data(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->width = 0;
	data->height = 0;
}

void		init(t_all *all)
{
	all->mlx = NULL;
	all->win = NULL;
	all->screenshot = 0;
	all->map.map = NULL;
	all->map.x_max = 0;
	all->map.y_max = 0;
	all->paint.tex_h = 0;
	all->paint.tex_w = 0;
	all->paint.tex_y = 0;
	all->paint.tex_x = 0;
	all->paint.wall_x = 0;
	all->paint.step = 0;
	all->paint.tex_pos = 0;
	all->sprites = NULL;
	all->sprites_count = 0;
	init_data(&all->img);
	init_data(&all->tex.no_img);
	init_data(&all->tex.so_img);
	init_data(&all->tex.ea_img);
	init_data(&all->tex.we_img);
	init_data(&all->tex.s_img);
	init_params(&all->params);
	init_ray(&all->ray);
	init_keys(&all->keys);
}
