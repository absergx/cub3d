/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:49:33 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 15:47:58 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	register_player(t_all *all, int x, int y, int *count)
{
	if (*count > 0)
		free_all(all, -11);
	all->ray.player_x = (double)x + 0.5;
	all->ray.player_y = (double)y + 0.5;
	all->params.dir = all->map.map[y][x];
	*count += 1;
}

static void	check_around(t_all *all, int x, int y)
{
	if (y - 1 < 0 || x - 1 < 0 || all->map.map[y - 1][x] == ' '
		|| all->map.map[y][x - 1] == ' ' || (all->map.map[y][x + 1] != '\0'
		&& all->map.map[y][x + 1] == ' ') || (y + 1 < all->map.y_max
		&& all->map.map[y + 1][x] == ' '))
		free_all(all, -10);
}

static void	find_player(t_all *all)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	count = 0;
	while (++y < all->map.y_max)
	{
		x = -1;
		if (!check_is_map(all->map.map[y]))
			free_all(all, -10);
		while (++x < all->map.x_max)
		{
			if (all->map.map[y][x] == 'N' || all->map.map[y][x] == 'S'
				|| all->map.map[y][x] == 'E' || all->map.map[y][x] == 'W')
				register_player(all, x, y, &count);
			else if (all->map.map[y][x] == '2' && !(sprites_alloc(all, x, y)))
				free_all(all, -1);
			if (all->map.map[y][x] == '2' || all->map.map[y][x] == '0')
				check_around(all, x, y);
		}
	}
	if (count == 0)
		free_all(all, -12);
}

static int	flood_fill(char **map, int x, int y, int y_max)
{
	if (map[y][x] == ' ' || y < 0 || x < 0 || map[y][x] == '\0'
		|| y >= y_max)
		return (0);
	if (map[y][x] == '1' || map[y][x] == '.')
		return (1);
	map[y][x] = '.';
	return (flood_fill(map, x - 1, y, y_max)
		&& flood_fill(map, x + 1, y, y_max)
		&& flood_fill(map, x, y - 1, y_max)
		&& flood_fill(map, x, y + 1, y_max));
}

int			validate_map(t_all *all)
{
	char	**tmp_map;
	int		i;

	i = -1;
	find_player(all);
	if (!(tmp_map = (char **)malloc(sizeof(char *) * all->map.y_max)))
		free_all(all, -1);
	while (++i < all->map.y_max)
		if (!(tmp_map[i] = ft_strdup(all->map.map[i])))
			free_all(all, -1);
	if (!flood_fill(tmp_map, (int)(all->ray.player_x - 0.5),
		(int)(all->ray.player_y - 0.5), all->map.y_max))
		free_all(all, -10);
	i = -1;
	while (++i < all->map.y_max)
		free(tmp_map[i]);
	free(tmp_map);
	return (1);
}
