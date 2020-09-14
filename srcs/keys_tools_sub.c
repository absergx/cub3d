/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_tools_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:50:18 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 16:39:02 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			close_win(t_all *all)
{
	free_all(all, 0);
	return (0);
}

int			check_map_step(char **map, int y, int x)
{
	if (map[y][x] == ' ' || map[y][x] == '0' || map[y][x] == 'N'
	|| map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
		return (1);
	return (0);
}

void		move_left(t_all *all)
{
	double	tmp_d_x;
	double	tmp_plane_x;

	tmp_d_x = all->ray.d_x;
	tmp_plane_x = all->ray.plane_x;
	all->ray.d_x = all->ray.d_x * cos(-0.05) - all->ray.d_y * sin(-0.05);
	all->ray.d_y = tmp_d_x * sin(-0.05) + all->ray.d_y * cos(-0.05);
	all->ray.plane_x = all->ray.plane_x * cos(-0.05)
		- all->ray.plane_y * sin(-0.05);
	all->ray.plane_y = tmp_plane_x * sin(-0.05)
		+ all->ray.plane_y * cos(-0.05);
}

void		move_right(t_all *all)
{
	double	tmp_d_x;
	double	tmp_plane_x;

	tmp_d_x = all->ray.d_x;
	tmp_plane_x = all->ray.plane_x;
	all->ray.d_x = all->ray.d_x * cos(0.05) - all->ray.d_y * sin(0.05);
	all->ray.d_y = tmp_d_x * sin(0.05) + all->ray.d_y * cos(0.05);
	all->ray.plane_x = all->ray.plane_x * cos(0.05)
		- all->ray.plane_y * sin(0.05);
	all->ray.plane_y = tmp_plane_x * sin(0.05)
		+ all->ray.plane_y * cos(0.05);
}
