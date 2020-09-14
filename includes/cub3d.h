/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:14:22 by memilio           #+#    #+#             */
/*   Updated: 2020/09/12 16:35:15 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2
# define FOV 66

void			handle_error(int code);
void			init(t_all *all);
void			hook_button(t_all *all);
void			press_w(t_all *all);
void			press_s(t_all *all);
void			press_a(t_all *all);
void			press_d(t_all *all);
void			press_l_r(t_all *all);
int				close_win(t_all *all);
void			move_left(t_all *all);
void			move_right(t_all *all);
int				check_map_step(char **map, int y, int x);
int				load_textures(t_all *all);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			paint_magic(t_all *all, int x);
int				get_color(t_data *img, int x, int y);
void			paint_sprite(t_all *all, t_sprite *sprite);
t_list			*parse_map(char *filename);
int				make_map(t_list **head, t_all *all);
int				parse_params(t_list	**head, t_params *params);
int				check_is_map(char *line);
int				parse_color_from_line(char *str, int *i);
int				parse_num_from_line(char *str, int *i);
void			free_line(void *content);
void			raycasting(t_all *all);
void			calc_start_dir(t_all *all);
int				shot_screen(t_all *all);
void			get_sprite(t_all *all);
int				sprites_alloc(t_all *all, int x, int y);
void			sort_sprites(t_all *all);
int				total_validate(t_all *all, int argc, char **argv);
int				validate_filename(char *filename, char *ext);
int				validate_map(t_all *all);
void			force_list_del(t_list **head, int errcode, t_params *params);
void			free_map(char **map, int errcode, t_list **head,
				t_params *params);
void			free_all(t_all *all, int errcode);

#endif
