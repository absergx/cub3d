/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:04:17 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 16:29:53 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_sprite_dist(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->sprites_count)
	{
		(all->sprites)[i].dist = sqrt(pow(all->ray.player_x
			- (all->sprites)[i].x, 2) + pow(all->ray.player_y
			- (all->sprites)[i].y, 2));
		i++;
	}
}

void		get_sprite(t_all *all)
{
	int		i;

	i = -1;
	if (!all->sprites_count)
		return ;
	calc_sprite_dist(all);
	sort_sprites(all);
	while (i++ < all->sprites_count)
		paint_sprite(all, &all->sprites[i]);
}

int			sprites_alloc(t_all *all, int x, int y)
{
	t_sprite	*new_sprites;
	int			i;

	i = 0;
	if (!(new_sprites = (t_sprite *)malloc(sizeof(t_sprite)
		* (all->sprites_count + 1))))
		free_all(all, -1);
	if (all->sprites_count)
	{
		while (i < all->sprites_count)
		{
			((t_sprite *)new_sprites)[i] = (all->sprites)[i];
			i++;
		}
		free(all->sprites);
	}
	all->sprites = new_sprites;
	(all->sprites)[i].x = (double)x + 0.5;
	(all->sprites)[i].y = (double)y + 0.5;
	(all->sprites)[i].i = all->sprites_count;
	all->sprites_count += 1;
	return (1);
}

static void	swap_sprites(t_sprite *s1, t_sprite *s2)
{
	double		tmp_x;
	double		tmp_y;
	double		tmp_dist;

	tmp_x = s1->x;
	tmp_y = s1->y;
	tmp_dist = s1->dist;
	s1->x = s2->x;
	s1->y = s2->y;
	s1->dist = s2->dist;
	s2->x = tmp_x;
	s2->y = tmp_y;
	s2->dist = tmp_dist;
}

void		sort_sprites(t_all *all)
{
	int			i;
	int			f;

	f = 1;
	while (f)
	{
		i = 0;
		f = 0;
		while (i < all->sprites_count)
		{
			if (i + 1 < all->sprites_count
				&& (all->sprites)[i].dist < (all->sprites)[i + 1].dist)
			{
				swap_sprites(&(all->sprites)[i], &(all->sprites)[i + 1]);
				f = 1;
			}
			i++;
		}
	}
}
