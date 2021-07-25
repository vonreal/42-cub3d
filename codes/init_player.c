/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 00:09:33 by jna               #+#    #+#             */
/*   Updated: 2021/05/25 02:34:19 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	init_s(t_info *info, int i, int j)
{
	info->ray.x = j + 0.5;
	info->ray.y = i + 0.5;
	info->ray.dir_x = 0;
	info->ray.dir_y = 1;
	info->ray.x_plane = -0.66;
	info->ray.y_plane = 0;
	info->ray.pos_x = info->ray.x;
	info->ray.pos_y = info->ray.y;
}

static void	init_n(t_info *info, int i, int j)
{
	info->ray.x = j + 0.5;
	info->ray.y = i + 0.5;
	info->ray.dir_x = 0;
	info->ray.dir_y = -1;
	info->ray.x_plane = 0.66;
	info->ray.y_plane = 0;
	info->ray.pos_x = info->ray.x;
	info->ray.pos_y = info->ray.y;
}

static void	init_w(t_info *info, int i, int j)
{
	info->ray.x = j + 0.5;
	info->ray.y = i + 0.5;
	info->ray.dir_x = -1;
	info->ray.dir_y = 0;
	info->ray.x_plane = 0;
	info->ray.y_plane = -0.66;
	info->ray.pos_x = info->ray.x;
	info->ray.pos_y = info->ray.y;
}

static void	init_e(t_info *info, int i, int j)
{
	info->ray.x = j + 0.5;
	info->ray.y = i + 0.5;
	info->ray.dir_x = 1;
	info->ray.dir_y = 0;
	info->ray.x_plane = 0;
	info->ray.y_plane = 0.66;
	info->ray.pos_x = info->ray.x;
	info->ray.pos_y = info->ray.y;
}

int			init_player(t_info *info, int i, int j)
{
	if (info->map[i][j] == 'S')
	{
		init_s(info, i, j);
		return (1);
	}
	if (info->map[i][j] == 'N')
	{
		init_n(info, i, j);
		return (1);
	}
	if (info->map[i][j] == 'W')
	{
		init_w(info, i, j);
		return (1);
	}
	if (info->map[i][j] == 'E')
	{
		init_e(info, i, j);
		return (1);
	}
	return (0);
}
