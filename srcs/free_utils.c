/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:23:12 by memilio           #+#    #+#             */
/*   Updated: 2020/09/13 12:38:42 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		force_list_del(t_list **head, int errcode, t_params *params)
{
	ft_lstclear(head, &free_line);
	if (params)
	{
		if (params->no_path)
			free(params->no_path);
		if (params->so_path)
			free(params->so_path);
		if (params->we_path)
			free(params->we_path);
		if (params->ea_path)
			free(params->ea_path);
		if (params->s_path)
			free(params->s_path);
	}
	if (errcode)
		handle_error(errcode);
}

void		free_line(void *content)
{
	free(content);
}

void		free_map(char **map, int errcode, t_list **head, t_params *params)
{
	int		i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			++i;
		}
		free(map);
	}
	if (head)
		force_list_del(head, errcode, params);
	if (errcode)
		handle_error(errcode);
}

void		free_all(t_all *all, int errcode)
{
	free_map(all->map.map, 0, NULL, &all->params);
	if (all->sprites)
		free(all->sprites);
	if (all->ray.buffer)
		free(all->ray.buffer);
	if (all->mlx && all->img.img && all->win)
	{
		mlx_destroy_image(all->mlx, all->img.img);
		mlx_destroy_window(all->mlx, all->win);
	}
	if (errcode)
		handle_error(errcode);
	else
		exit(0);
}
