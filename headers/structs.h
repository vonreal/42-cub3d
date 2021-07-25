/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:19:29 by jna               #+#    #+#             */
/*   Updated: 2021/05/25 02:34:08 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_key
{
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
}				t_key;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;

typedef struct	s_sprite
{
	float		*sprite_x;
	float		*sprite_y;
	float		*spritedist;
	int			spritenum;
	int			*spriteord;
	double		*zbuf;
	int			spritew;
	int			spriteh;
	double		sprx;
	double		spry;
	double		invdet;
	double		transx;
	double		transy;
	int			spritescreenx;
	int			drawstartx;
	int			drawstarty;
	int			drawendx;
	int			drawendy;
	int			texx;
	int			texy;
}				t_sprite;

typedef struct	s_texture
{
	int			texhi;
	int			texwe;
	int			texnum;
	int			texx;
	int			texy;
	float		wallx;
	float		texpos;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_img		sprite;
	int			*tex[5];
	double		step;
	int			color;
}				t_texture;

typedef struct	s_ray
{
	float		x;
	float		y;
	float		pos_x;
	float		pos_y;
	int			map_x;
	int			map_y;
	float		delta_distx;
	float		delta_disty;
	float		side;
	float		pwd;
	int			drawstart;
	int			drawend;
	float		ray_dir_x;
	float		ray_dir_y;
	float		dir_x;
	float		dir_y;
	double		side_dist_x;
	double		side_dist_y;
	float		x_plane;
	float		y_plane;
	int			hit;
	int			step_x;
	int			step_y;
	float		olddirx;
	float		oldplanex;
	float		camera_x;
	float		dist;
	double		movespeed;
	double		rotspeed;
	int			height;
}				t_ray;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_elements
{
	int			r1;
	int			r2;
	int			k;
	char		*map;
	int			begmap;
	int			endmap;
	char		*path[5];
	int			color[2][3];
	int			c[3];
	int			f[3];
	int			err;
	int			flag;
}				t_elements;

typedef struct	s_info
{
	t_mlx		mlx;
	t_img		img;
	t_ray		ray;
	t_sprite	sprite;
	t_texture	texture;
	t_elements	infos;
	char		**map;
	t_key		keys;
}				t_info;

#endif
