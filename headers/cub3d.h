/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:19:37 by jna               #+#    #+#             */
/*   Updated: 2021/05/25 02:40:38 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "structs.h"
# include "key_codes.h"
# include "../librarys/minilibx/mlx.h"
# include "../librarys/libft/libft.h"
# include "../librarys/get_next_line/get_next_line.h"

# define NORTH	0
# define SOUTH	1
# define EAST	2
# define WEST	3
# define SPRITE	4

# define FLOOR		0
# define CEILLING 	1

# define SCREEN_MAX_W 2560
# define SCREEN_MAX_H 1440

/*
**			init
*/
void		init_info(t_info *info);
int			init_player(t_info *info, int i, int j);
void		init_key(t_key *keys);

/*
**			valid check of argument
*/
void		valid_arg(t_info *info, int argc, char **argv);

/*
**			parsing .cub file
*/
void		parsing(t_info *info);
void		parsing_elements(t_info *info);
void		parsing_map(t_info *info);

/*
**			valid check of map
*/
void		valid_wall(t_info *info);
void		game(t_info *info);

/*
**			error check
*/
void		check_content(t_info *info, int i, int j);
void		error_parsing(char *msg);

/*
**			game
*/
void		begin_game(t_info *info);
void		start_game(t_info *info);

/*
**			load image from path in cub file
*/
void		load_image_no(t_info *info, int **tex, char *path);
void		load_image_so(t_info *info, int **tex, char *path);
void		load_image_ea(t_info *info, int **tex, char *path);
void		load_image_we(t_info *info, int **tex, char *path);
void		load_image_sp(t_info *info, int **tex, char *path);

/*
**			handle sprite
*/
void		cal_sprite(t_info *info);
void		set_sprite(t_info *info);

/*
**			ray casting DDA
*/
void		init_ray(t_info *info, int x);
void		calc_step_side_dist(t_info *info);
void		dda(t_info *info);
void		set_draw_point(t_info *info);
void		find_tex(t_info *info);
void		set_text_value(t_info *info);

/*
**			draw
*/
void		draw(t_info *info, int x);
void		render(t_info *info, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		trans(t_info *info, t_sprite *sprite);
void		draw_sprite(t_info *info, t_sprite *spr);

/*
**			handle key
*/
int			key_press(t_info *info);
int			key_pressed(int key, t_info *info);
int			key_released(int key, t_key *keys);

/*
**			uile
*/
int			is_numbers(char *str);
int			close_window(t_info *info);
void		save_bmp(t_info *info);

#endif
