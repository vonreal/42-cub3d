/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 00:21:36 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 23:43:02 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	init_mlx(t_info *info, t_elements *infos, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	info->img.img = mlx_new_image(mlx->mlx, infos->r1, infos->r2);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits_per_pixel,
			&info->img.line_length, &info->img.endian);
}

static void	set_player(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->ray.dist = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (init_player(info, i, j) == 1)
				return ;
			j++;
		}
		i++;
	}
}

static void	init_sprite(t_info *info)
{
	info->ray.movespeed = 0.50;
	info->ray.rotspeed = 0.10;
	set_sprite(info);
}

static void	load_textures(t_info *info)
{
	load_image_no(info, &info->texture.tex[0], info->infos.path[0]);
	load_image_so(info, &info->texture.tex[1], info->infos.path[1]);
	load_image_ea(info, &info->texture.tex[2], info->infos.path[2]);
	load_image_we(info, &info->texture.tex[3], info->infos.path[3]);
	load_image_sp(info, &info->texture.tex[4], info->infos.path[4]);
}

void		begin_game(t_info *info)
{
	init_mlx(info, &info->infos, &info->mlx);
	set_player(info);
	init_sprite(info);
	load_textures(info);
	cal_sprite(info);
}
