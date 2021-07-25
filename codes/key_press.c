/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 02:20:45 by jna               #+#    #+#             */
/*   Updated: 2021/05/25 02:34:29 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	go_and_back(t_info *info, double move)
{
	int	x;
	int	y;

	y = (int)(info->ray.pos_y);
	x = (int)(info->ray.pos_x + info->ray.dir_x * move);
	if (info->map[y][x] != '1')
		info->ray.pos_x += info->ray.dir_x * move;
	x = (int)(info->ray.pos_x);
	y = (int)(info->ray.pos_y + info->ray.dir_y * move);
	if (info->map[y][x] != '1')
		info->ray.pos_y += info->ray.dir_y * move;
}

static void	right_and_left(t_info *info, double move)
{
	int	x;
	int	y;

	y = (int)(info->ray.pos_y);
	x = (int)(info->ray.pos_x + info->ray.x_plane * move);
	if (info->map[y][x] != '1')
		info->ray.pos_x += info->ray.x_plane * move;
	x = (int)(info->ray.pos_x);
	y = (int)(info->ray.pos_y + info->ray.y_plane * move);
	if (info->map[y][x] != '1')
		info->ray.pos_y += info->ray.y_plane * move;
}

static void	turn_left(t_info *info)
{
	info->ray.olddirx = info->ray.dir_x;
	info->ray.dir_x = info->ray.dir_x * cos(-info->ray.rotspeed)
		- info->ray.dir_y * sin(-info->ray.rotspeed);
	info->ray.dir_y = info->ray.olddirx * sin(-info->ray.rotspeed)
		+ info->ray.dir_y * cos(-info->ray.rotspeed);
	info->ray.oldplanex = info->ray.x_plane;
	info->ray.x_plane = info->ray.x_plane * cos(-info->ray.rotspeed)
		- info->ray.y_plane * sin(-info->ray.rotspeed);
	info->ray.y_plane = info->ray.oldplanex * sin(-info->ray.rotspeed)
		+ info->ray.y_plane * cos(-info->ray.rotspeed);
}

static void	turn_right(t_info *info)
{
	info->ray.olddirx = info->ray.dir_x;
	info->ray.dir_x = info->ray.dir_x * cos(info->ray.rotspeed)
		- info->ray.dir_y * sin(info->ray.rotspeed);
	info->ray.dir_y = info->ray.olddirx * sin(info->ray.rotspeed)
		+ info->ray.dir_y * cos(info->ray.rotspeed);
	info->ray.oldplanex = info->ray.x_plane;
	info->ray.x_plane = info->ray.x_plane * cos(info->ray.rotspeed)
		- info->ray.y_plane * sin(info->ray.rotspeed);
	info->ray.y_plane = info->ray.oldplanex * sin(info->ray.rotspeed)
		+ info->ray.y_plane * cos(info->ray.rotspeed);
}

int			key_press(t_info *info)
{
	if (info->keys.key_w == 1)
		go_and_back(info, info->ray.movespeed);
	if (info->keys.key_s == 1)
		go_and_back(info, -info->ray.movespeed);
	if (info->keys.key_a == 1)
		right_and_left(info, -info->ray.movespeed);
	if (info->keys.key_d == 1)
		right_and_left(info, info->ray.movespeed);
	if (info->keys.key_left == 1)
		turn_left(info);
	if (info->keys.key_right == 1)
		turn_right(info);
	return (0);
}
