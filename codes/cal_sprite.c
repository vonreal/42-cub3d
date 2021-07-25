/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 00:40:25 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 20:31:26 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void		sort_to_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < amount)
	{
		j = -1;
		while (++j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
		}
	}
}

static void	sort(int *order, float *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	i = 0;
	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_to_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}

void		cal_sprite(t_info *info)
{
	float	i;
	float	j;
	int		k;

	k = 0;
	while (k != info->sprite.spritenum)
	{
		info->sprite.spriteord[k] = k;
		i = (info->ray.pos_x - info->sprite.sprite_x[k]);
		j = (info->ray.pos_y - info->sprite.sprite_y[k]);
		info->sprite.spritedist[k] = i * i + j * j;
		k++;
	}
	sort(info->sprite.spriteord, \
		info->sprite.spritedist, info->sprite.spritenum);
}
