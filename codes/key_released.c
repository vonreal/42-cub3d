/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:29:55 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 22:51:56 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void		init_key(t_key *keys)
{
	keys->key_w = 0;
	keys->key_s = 0;
	keys->key_a = 0;
	keys->key_d = 0;
	keys->key_left = 0;
	keys->key_right = 0;
}

int			key_pressed(int key, t_info *info)
{
	if (key == KEY_W)
		info->keys.key_w = 1;
	if (key == KEY_S)
		info->keys.key_s = 1;
	if (key == KEY_A)
		info->keys.key_a = 1;
	if (key == KEY_D)
		info->keys.key_d = 1;
	if (key == KEY_LEFT)
		info->keys.key_left = 1;
	if (key == KEY_RIGHT)
		info->keys.key_right = 1;
	if (key == KEY_ESC)
		close_window(info);
	key_press(info);
	return (0);
}

int			key_released(int key, t_key *keys)
{
	if (key == KEY_W)
		keys->key_w = 0;
	if (key == KEY_S)
		keys->key_s = 0;
	if (key == KEY_A)
		keys->key_a = 0;
	if (key == KEY_D)
		keys->key_d = 0;
	if (key == KEY_LEFT)
		keys->key_left = 0;
	if (key == KEY_RIGHT)
		keys->key_right = 0;
	return (0);
}
