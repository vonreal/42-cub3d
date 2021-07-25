/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 01:42:02 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 20:39:00 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void		set_text_value(t_info *info)
{
	info->texture.texx = (int)(info->texture.wallx * \
									(float)info->texture.texwe);
	if ((info->ray.side == 0) && (info->ray.ray_dir_x > 0))
		info->texture.texx = info->texture.texwe - info->texture.texx - 1;
	if ((info->ray.side == 0) && (info->ray.ray_dir_y < 0))
		info->texture.texx = info->texture.texwe - info->texture.texx - 1;
	info->texture.step = 1.0 * info->texture.texhi / info->ray.height;
	info->texture.texpos = (info->ray.drawstart - info->infos.r2 / 2
			+ info->ray.height / 2) * info->texture.step;
}

static void	draw_ceilling(t_info *info, int x, int y1, int y2)
{
	int	i;
	int	color;
	int	rgb[3];

	i = y1;
	rgb[0] = info->infos.color[CEILLING][0];
	rgb[1] = info->infos.color[CEILLING][1];
	rgb[2] = info->infos.color[CEILLING][2];
	color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	while (i <= y2)
	{
		render(info, x, i, color);
		i++;
	}
}

static void	draw_texture(t_info *info, int x)
{
	int	y;
	int	k;

	y = info->ray.drawstart;
	while (y < info->ray.drawend)
	{
		info->texture.texy = (int)info->texture.texpos & \
									(info->texture.texhi - 1);
		info->texture.texpos += info->texture.step;
		k = info->texture.texhi * info->texture.texy + info->texture.texx;
		info->texture.color = info->texture.tex[info->texture.texnum][k];
		render(info, x, y, info->texture.color);
		y++;
	}
}

static void	draw_floor(t_info *info, int x, int y1, int y2)
{
	int	i;
	int	color;
	int	rgb[3];

	i = y1;
	rgb[0] = info->infos.color[FLOOR][0];
	rgb[1] = info->infos.color[FLOOR][1];
	rgb[2] = info->infos.color[FLOOR][2];
	color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	while (i <= y2)
	{
		render(info, x, i, color);
		i++;
	}
}

void		draw(t_info *info, int x)
{
	draw_ceilling(info, x, 0, info->ray.drawstart);
	draw_texture(info, x);
	draw_floor(info, x, info->ray.drawend, info->infos.r2);
}
