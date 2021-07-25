/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 00:33:25 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 20:34:45 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	load_image_no(t_info *info, int **tex, char *path)
{
	info->texture.north.img = mlx_xpm_file_to_image(info->mlx.mlx, path,
			&info->texture.texwe, &info->texture.texhi);
	if (info->texture.north.img == NULL)
		error_parsing("load image north fail");
	info->texture.north.addr = mlx_get_data_addr(info->texture.north.img,
			&info->texture.north.bits_per_pixel,
			&info->texture.north.line_length, &info->texture.north.endian);
	*tex = (int *)info->texture.north.addr;
}

void	load_image_so(t_info *info, int **tex, char *path)
{
	info->texture.south.img = mlx_xpm_file_to_image(info->mlx.mlx, path,
			&info->texture.texwe, &info->texture.texhi);
	if (info->texture.south.img == NULL)
		error_parsing("load image south fail");
	info->texture.south.addr = mlx_get_data_addr(info->texture.south.img,
		&info->texture.south.bits_per_pixel, &info->texture.south.line_length,
		&info->texture.south.endian);
	*tex = (int *)info->texture.south.addr;
}

void	load_image_ea(t_info *info, int **tex, char *path)
{
	info->texture.east.img = mlx_xpm_file_to_image(info->mlx.mlx, path,
			&info->texture.texwe, &info->texture.texhi);
	if (info->texture.east.img == NULL)
		error_parsing("load image east fail");
	info->texture.east.addr = mlx_get_data_addr(info->texture.east.img,
		&info->texture.east.bits_per_pixel, &info->texture.east.line_length,
		&info->texture.east.endian);
	*tex = (int *)info->texture.east.addr;
}

void	load_image_we(t_info *info, int **tex, char *path)
{
	info->texture.west.img = mlx_xpm_file_to_image(info->mlx.mlx, path,
			&info->texture.texwe, &info->texture.texhi);
	if (info->texture.west.img == NULL)
		error_parsing("load image west fail");
	info->texture.west.addr = mlx_get_data_addr(info->texture.west.img,
		&info->texture.west.bits_per_pixel, &info->texture.west.line_length,
		&info->texture.west.endian);
	*tex = (int *)info->texture.west.addr;
}

void	load_image_sp(t_info *info, int **tex, char *path)
{
	info->texture.sprite.img = mlx_xpm_file_to_image(info->mlx.mlx,
			path, &info->texture.texwe, &info->texture.texhi);
	if (info->texture.sprite.img == NULL)
		error_parsing("load image sprite fail");
	info->texture.sprite.addr = mlx_get_data_addr(info->texture.sprite.img,
		&info->texture.sprite.bits_per_pixel, &info->texture.sprite.line_length,
		&info->texture.sprite.endian);
	*tex = (int *)info->texture.sprite.addr;
}
