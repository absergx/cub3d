/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 16:44:28 by memilio           #+#    #+#             */
/*   Updated: 2020/09/10 17:03:53 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_textures_addr(t_all *all)
{
	if (!(all->tex.no_img.addr = mlx_get_data_addr(all->tex.no_img.img,
		&all->tex.no_img.bits_per_pixel, &all->tex.no_img.line_length,
		&all->tex.no_img.endian)))
		return (0);
	if (!(all->tex.so_img.addr = mlx_get_data_addr(all->tex.so_img.img,
		&all->tex.so_img.bits_per_pixel, &all->tex.so_img.line_length,
		&all->tex.so_img.endian)))
		return (0);
	if (!(all->tex.ea_img.addr = mlx_get_data_addr(all->tex.ea_img.img,
		&all->tex.ea_img.bits_per_pixel, &all->tex.ea_img.line_length,
		&all->tex.ea_img.endian)))
		return (0);
	if (!(all->tex.we_img.addr = mlx_get_data_addr(all->tex.we_img.img,
		&all->tex.we_img.bits_per_pixel, &all->tex.we_img.line_length,
		&all->tex.we_img.endian)))
		return (0);
	if (!(all->tex.s_img.addr = mlx_get_data_addr(all->tex.s_img.img,
		&all->tex.s_img.bits_per_pixel, &all->tex.s_img.line_length,
		&all->tex.s_img.endian)))
		return (0);
	return (1);
}

int			load_textures(t_all *all)
{
	if (!(all->tex.no_img.img = mlx_xpm_file_to_image(all->mlx,
		all->params.no_path, &all->tex.no_img.width, &all->tex.no_img.height)))
		return (0);
	if (!(all->tex.so_img.img = mlx_xpm_file_to_image(all->mlx,
		all->params.so_path, &all->tex.so_img.width, &all->tex.so_img.height)))
		return (0);
	if (!(all->tex.ea_img.img = mlx_xpm_file_to_image(all->mlx,
		all->params.ea_path, &all->tex.ea_img.width, &all->tex.ea_img.height)))
		return (0);
	if (!(all->tex.we_img.img = mlx_xpm_file_to_image(all->mlx,
		all->params.we_path, &all->tex.we_img.width, &all->tex.we_img.height)))
		return (0);
	if (!(all->tex.s_img.img = mlx_xpm_file_to_image(all->mlx,
		all->params.s_path, &all->tex.s_img.width, &all->tex.s_img.height)))
		return (0);
	return (get_textures_addr(all) ? 1 : 0);
}
