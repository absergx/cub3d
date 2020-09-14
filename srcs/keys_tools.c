/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:34:31 by memilio           #+#    #+#             */
/*   Updated: 2020/09/10 17:03:46 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		press_w(t_all *all)
{
	if (check_map_step(all->map.map, (int)all->ray.player_y,
	(int)(all->ray.player_x + all->ray.d_x * 0.21)))
		all->ray.player_x += all->ray.d_x * 0.2;
	if (check_map_step(all->map.map, (int)(all->ray.player_y + all->ray.d_y
	* 0.21), (int)all->ray.player_x))
		all->ray.player_y += all->ray.d_y * 0.2;
}

void		press_s(t_all *all)
{
	if (check_map_step(all->map.map, (int)all->ray.player_y,
	(int)(all->ray.player_x - all->ray.d_x * 0.21)))
		all->ray.player_x -= all->ray.d_x * 0.2;
	if (check_map_step(all->map.map, (int)(all->ray.player_y - all->ray.d_y
	* 0.21), (int)all->ray.player_x))
		all->ray.player_y -= all->ray.d_y * 0.2;
}

void		press_a(t_all *all)
{
	if (check_map_step(all->map.map, (int)all->ray.player_y,
	(int)(all->ray.player_x - all->ray.plane_x * 0.21)))
		all->ray.player_x -= all->ray.plane_x * 0.2;
	if (check_map_step(all->map.map, (int)(all->ray.player_y
	- all->ray.plane_y * 0.21), (int)all->ray.player_x))
		all->ray.player_y -= all->ray.plane_y * 0.2;
}

void		press_d(t_all *all)
{
	if (check_map_step(all->map.map, (int)all->ray.player_y,
	(int)(all->ray.player_x + all->ray.plane_x * 0.21)))
		all->ray.player_x += all->ray.plane_x * 0.2;
	if (check_map_step(all->map.map, (int)(all->ray.player_y
	+ all->ray.plane_y * 0.21), (int)all->ray.player_x))
		all->ray.player_y += all->ray.plane_y * 0.2;
}

void		press_l_r(t_all *all)
{
	if (all->keys.left)
		move_left(all);
	if (all->keys.right)
		move_right(all);
}
