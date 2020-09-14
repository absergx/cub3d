/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:08:00 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 12:39:39 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_error_sub(int code)
{
	if (code == -11)
		ft_putstr_fd("More than one player on map", 0);
	else if (code == -12)
		ft_putstr_fd("No player on map", 0);
	else if (code == -13)
		ft_putstr_fd("Map has empty lines", 0);
	else if (code == -14)
		ft_putstr_fd("Getting pointer from mlx failed", 0);
}

void		handle_error(int code)
{
	ft_putstr_fd("Error\n", 0);
	if (code == -1)
		ft_putstr_fd("Allocate memory fail", 0);
	else if (code == -2)
		ft_putstr_fd("Loading textures fail", 0);
	else if (code == -3)
		ft_putstr_fd("File opening failed", 0);
	else if (code == -4)
		ft_putstr_fd("Map filename is not .cub", 0);
	else if (code == -5)
		ft_putstr_fd("Texture filename is not .xpm", 0);
	else if (code == -6)
		ft_putstr_fd("Wrong flag, try --save", 0);
	else if (code == -7)
		ft_putstr_fd("No map in arguments", 0);
	else if (code == -8)
		ft_putstr_fd("Too many arguments", 0);
	else if (code == -9)
		ft_putstr_fd("Map parameters are invalid", 0);
	else if (code == -10)
		ft_putstr_fd("Map is invalid", 0);
	else
		handle_error_sub(code);
	ft_putchar_fd('\n', 0);
	exit(0);
}
