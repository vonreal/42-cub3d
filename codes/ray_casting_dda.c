/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 01:34:50 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 20:38:36 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_ray(t_info *info, int x)
{
	info->ray.camera_x = 2 * x / (float)info->infos.r1 - 1;
	info->ray.ray_dir_x = info->ray.dir_x
		+ info->ray.x_plane * info->ray.camera_x;
	info->ray.ray_dir_y = info->ray.dir_y
		+ info->ray.y_plane * info->ray.camera_x;
	info->ray.map_x = (int)info->ray.pos_x;
	info->ray.map_y = (int)info->ray.pos_y;
	info->ray.delta_distx = fabs(1 / info->ray.ray_dir_x);
	info->ray.delta_disty = fabs(1 / info->ray.ray_dir_y);
}

void	calc_step_side_dist(t_info *info)
{
	if (info->ray.ray_dir_x < 0)
	{
		info->ray.step_x = -1;
		info->ray.side_dist_x = ((float)info->ray.pos_x
				- (float)info->ray.map_x) * info->ray.delta_distx;
	}
	else
	{
		info->ray.step_x = 1;
		info->ray.side_dist_x = ((float)info->ray.map_x + 1.0
				- info->ray.pos_x) * info->ray.delta_distx;
	}
	if (info->ray.ray_dir_y < 0)
	{
		info->ray.step_y = -1;
		info->ray.side_dist_y = ((float)info->ray.pos_y
				- (float)info->ray.map_y) * info->ray.delta_disty;
	}
	else
	{
		info->ray.step_y = 1;
		info->ray.side_dist_y = ((float)info->ray.map_y
				+ 1.0 - info->ray.pos_y) * info->ray.delta_disty;
	}
}

void	dda(t_info *info)
{
	info->ray.hit = 0;
	while (info->ray.hit == 0)
	{
		if (info->ray.side_dist_x < info->ray.side_dist_y)
		{
			info->ray.side_dist_x += info->ray.delta_distx;
			info->ray.map_x += info->ray.step_x;
			info->ray.side = 0;
		}
		else
		{
			info->ray.side_dist_y += info->ray.delta_disty;
			info->ray.map_y += info->ray.step_y;
			info->ray.side = 1;
		}
		if (info->map[(info->ray.map_y)][(info->ray.map_x)] == '1')
			info->ray.hit = 1;
	}
}

void	set_draw_point(t_info *info)
{
	if (info->ray.side == 0)
		info->ray.pwd = (info->ray.map_x - info->ray.pos_x
				+ (1 - info->ray.step_x) / 2) / info->ray.ray_dir_x;
	else
		info->ray.pwd = (info->ray.map_y - info->ray.pos_y
				+ (1 - info->ray.step_y) / 2) / info->ray.ray_dir_y;
	info->ray.height = (int)((float)info->infos.r2 / info->ray.pwd);
	info->ray.drawstart = -info->ray.height / 2 + info->infos.r2 / 2;
	if (info->ray.drawstart < 0)
		info->ray.drawstart = 0;
	info->ray.drawend = info->ray.height / 2 + info->infos.r2 / 2;
	if (info->ray.drawend >= info->infos.r2)
		info->ray.drawend = info->infos.r2 - 1;
}

void	find_tex(t_info *info)
{
	info->texture.texnum = 0;
	if (info->ray.side == 0)
	{
		info->texture.texnum = 2;
		if (info->ray.ray_dir_x > 0)
			info->texture.texnum = 3;
		info->texture.wallx = info->ray.pos_y
			+ info->ray.pwd * info->ray.ray_dir_y;
	}
	else
	{
		info->texture.texnum = 1;
		if (info->ray.ray_dir_y > 0)
			info->texture.texnum = 0;
		info->texture.wallx = info->ray.pos_x
			+ info->ray.pwd * info->ray.ray_dir_x;
	}
	info->texture.wallx -= floor((info->texture.wallx));
}
