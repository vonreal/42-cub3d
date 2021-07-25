/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 00:00:50 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 23:59:54 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int			close_window(t_info *info)
{
	mlx_destroy_window(info->mlx.mlx, info->mlx.win);
	exit(0);
}

static void	ray_sprite(t_info *info)
{
	int	i;

	i = 0;
	while (i != info->sprite.spritenum)
	{
		info->sprite.sprx = info->sprite.sprite_x[info->sprite.spriteord[i]]
			- info->ray.pos_x;
		info->sprite.spry = info->sprite.sprite_y[info->sprite.spriteord[i]]
			- info->ray.pos_y;
		trans(info, &info->sprite);
		draw_sprite(info, &info->sprite);
		i++;
	}
}

static void	ray_casting(t_info *info)
{
	int		x;

	x = 0;
	while (x < info->infos.r1)
	{
		init_ray(info, x);
		calc_step_side_dist(info);
		dda(info);
		set_draw_point(info);
		find_tex(info);
		set_text_value(info);
		draw(info, x);
		info->sprite.zbuf[x] = info->ray.pwd;
		x++;
	}
}

static int	game_loop(t_info *info)
{
	ray_casting(info);
	ray_sprite(info);
	if (info->infos.flag == 1)
	{
		save_bmp(info);
		exit(0);
	}
	mlx_put_image_to_window(info->mlx.mlx, info->mlx.win, info->img.img, 0, 0);
	mlx_do_sync(info->mlx.mlx);
	return (0);
}

void		start_game(t_info *info)
{
	if (info->infos.flag == 1)
	{
		info->mlx.win = \
			mlx_new_window(info->mlx.mlx, 0, 0, "cub3d");
	}
	else
	{
		info->mlx.win = \
		mlx_new_window(info->mlx.mlx, info->infos.r1, info->infos.r2, "cub3d");
	}
	mlx_loop_hook(info->mlx.mlx, &game_loop, info);
	mlx_hook(info->mlx.win, 2, 1L << 0, &key_pressed, info);
	mlx_hook(info->mlx.win, 3, 1L << 1, &key_released, &info->keys);
	mlx_hook(info->mlx.win, 17, 0, &close_window, info);
	mlx_loop(info->mlx.mlx);
}
