/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:38:26 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 23:39:46 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	init_elements(t_elements *infos)
{
	infos->err = 0;
	infos->begmap = 0;
	infos->path[NORTH] = NULL;
	infos->path[SOUTH] = NULL;
	infos->path[EAST] = NULL;
	infos->path[WEST] = NULL;
	infos->path[SPRITE] = NULL;
	infos->r1 = -1;
	infos->r2 = -1;
	infos->color[FLOOR][0] = -1;
	infos->color[FLOOR][1] = -1;
	infos->color[FLOOR][2] = -1;
	infos->color[CEILLING][0] = -1;
	infos->color[CEILLING][1] = -1;
	infos->color[CEILLING][2] = -1;
	infos->flag = -1;
}

static void	init_texture(t_texture *tex)
{
	tex->texwe = 64;
	tex->texhi = 64;
}

void		init_info(t_info *info)
{
	init_elements(&info->infos);
	init_texture(&info->texture);
}
