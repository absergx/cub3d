/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:47:30 by memilio           #+#    #+#             */
/*   Updated: 2020/09/09 17:50:14 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct		s_sprite
{
	int				i;
	double			x;
	double			y;
	double			dist;
}					t_sprite;

typedef struct		s_ray
{
	double			camera_x;
	double			d_x;
	double			d_y;
	double			r_d_x;
	double			r_d_y;
	double			plane_x;
	double			plane_y;
	double			dist_x;
	double			dist_y;
	double			dlt_d_x;
	double			dlt_d_y;
	double			player_x;
	double			player_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				wall_start;
	int				wall_height;
	int				wall_end;
	int				wall_side;
	double			wall_dist;
	double			*buffer;
}					t_ray;

typedef struct		s_paint
{
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
	int				tex_h;
	int				tex_w;
}					t_paint;

typedef struct		s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_keys;

typedef struct		s_params
{
	int				r;
	int				r_xy[2];
	int				no;
	char			*no_path;
	int				so;
	char			*so_path;
	int				we;
	char			*we_path;
	int				ea;
	char			*ea_path;
	int				s;
	char			*s_path;
	int				f;
	unsigned long	f_col;
	int				c;
	unsigned long	c_col;
	char			dir;
}					t_params;

typedef struct		s_sp_p
{
	double			sprite_x;
	double			sprite_y;
	double			invdet;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_h;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_w;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
}					t_sp_p;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
}					t_data;

typedef struct		s_map
{
	char			**map;
	int				x_max;
	int				y_max;
}					t_map;

typedef struct		s_textures
{
	t_data			no_img;
	t_data			so_img;
	t_data			we_img;
	t_data			ea_img;
	t_data			s_img;
}					t_textures;

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	t_params		params;
	t_data			img;
	t_map			map;
	t_ray			ray;
	t_keys			keys;
	t_textures		tex;
	t_paint			paint;
	t_sprite		*sprites;
	t_sp_p			sp_p;
	int				sprites_count;
	int				screenshot;
}					t_all;

#endif
