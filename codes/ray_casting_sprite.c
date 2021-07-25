/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 02:02:19 by jna               #+#    #+#             */
/*   Updated: 2021/05/25 02:36:31 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	check_sprite_size(t_info *info, t_sprite *spr)
{
	spr->spriteh = abs((int)(info->infos.r2 / spr->transy));
	spr->drawstarty = -spr->spriteh / 2 + info->infos.r2 / 2;
	if (spr->drawstarty < 0)
		spr->drawstarty = 0;
	spr->drawendy = spr->spriteh / 2 + info->infos.r2 / 2;
	if (spr->drawendy >= info->infos.r2)
		spr->drawendy = info->infos.r2 - 1;
	spr->spritew = abs((int)(info->infos.r2 / spr->transy));
	spr->drawstartx = -spr->spritew / 2 + spr->spritescreenx;
	if (spr->drawstartx < 0)
		spr->drawstartx = 0;
	spr->drawendx = spr->spritew / 2 + spr->spritescreenx;
	if (spr->drawendx >= info->infos.r1)
		spr->drawendx = info->infos.r1 - 1;
}

static void	check_color(t_info *info, t_sprite *spr, int x)
{
	int	y;
	int	d;
	int	color;
	int	j;

	y = spr->drawstarty;
	while (y < spr->drawendy)
	{
		d = y * 256 - info->infos.r2 * 128 + spr->spriteh * 128;
		spr->texy = ((d * info->texture.texhi) / spr->spriteh / 256);
		j = (info->texture.texwe * spr->texy + spr->texx);
		color = info->texture.tex[4][j];
		if ((color & 0x00FFFFFF) != 0)
			render(info, x, y, color);
		y++;
	}
}

void		trans(t_info *info, t_sprite *sprite)
{
	sprite->invdet = 1.0 / (info->ray.x_plane * info->ray.dir_y
			- info->ray.dir_x * info->ray.y_plane);
	sprite->transx = sprite->invdet * (info->ray.dir_y * sprite->sprx
			- info->ray.dir_x * sprite->spry);
	sprite->transy = sprite->invdet * (-info->ray.y_plane * sprite->sprx
			+ info->ray.x_plane * sprite->spry);
	sprite->spritescreenx = (int)((info->infos.r1 / 2)
			* (1 + sprite->transx / sprite->transy));
	check_sprite_size(info, sprite);
}

void		draw_sprite(t_info *info, t_sprite *spr)
{
	int	k;

	cal_sprite(info);
	k = spr->drawstartx;
	while (k < spr->drawendx)
	{
		spr->texx = (int)((256 * (k
						- (-spr->spritew / 2 + spr->spritescreenx))
					* info->texture.texwe / spr->spritew) / 256);
		if ((spr->transy > 0) && (k > 0) && (k < info->infos.r1)
			&& (spr->transy < spr->zbuf[k]))
			check_color(info, spr, k);
		k++;
	}
}
