/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:27:44 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 20:32:07 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	sprite_count(t_info *info)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(info->infos.map, O_RDONLY);
	count = 0;
	while ((get_next_line(fd, &line) > 0))
	{
		free(line);
		count++;
	}
	free(line);
	if (get_next_line(fd, &line) < 0)
		info->infos.err = -1;
	free(line);
	close(fd);
	return (count);
}

static void	sprite_pos(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->sprite.spritenum = 0;
	while (info->map[i])
	{
		j = 0;
		while (i < info->infos.endmap && info->map[i][j])
		{
			if (info->map[i][j] == '2')
			{
				info->sprite.sprite_x[info->sprite.spritenum] = j + 0.5;
				info->sprite.sprite_y[info->sprite.spritenum] = i + 0.5;
				info->sprite.spritedist[info->sprite.spritenum] = 0;
				info->sprite.spritenum++;
			}
			j++;
		}
		i++;
	}
}

void		set_sprite(t_info *info)
{
	int	count;

	count = sprite_count(info);
	if (count != 0)
	{
		info->sprite.sprite_x = malloc(sizeof(float) * count + sizeof(float));
		info->sprite.sprite_y = malloc(sizeof(float) * count + sizeof(float));
		info->sprite.spritedist = malloc(sizeof(float) * count + sizeof(float));
		info->sprite.spriteord = malloc(sizeof(int) * count + sizeof(float));
		info->sprite.zbuf = malloc((sizeof(double) * (info->infos.r1)));
		sprite_pos(info);
	}
}
