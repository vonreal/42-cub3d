/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 01:53:21 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 18:30:23 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void		render(t_info *info, int x, int y, int color)
{
	char	*dst;

	if ((y == info->infos.r2) || (x == info->infos.r1))
		return ;
	dst = NULL;
	dst = info->img.addr + (y * info->img.line_length + x
			* (info->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
