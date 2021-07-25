/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 02:15:38 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 23:50:11 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	create(int fd, t_info *info)
{
	int32_t	x;
	int32_t	y;
	int		color;

	y = info->infos.r2 - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < info->infos.r1)
		{
			color = *(unsigned int *)(info->img.addr
					+ (y * info->img.line_length)
					+ x * (info->img.bits_per_pixel / 8));
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
	close(fd);
	exit(0);
}

void		save_bmp(t_info *info)
{
	int		fd;
	char	bitmap[54];

	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		write(2, "Error\nСreating a screenshot resulted in an error", 49);
		exit(-1);
	}
	ft_bzero(bitmap, 54);
	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int *)(bitmap + 2)) = info->infos.r2 * info->infos.r1 * 4 + 54;
	*(int *)(bitmap + 10) = 54;
	*(int *)(bitmap + 14) = 40;
	*(int *)(bitmap + 18) = info->infos.r1;
	*(int *)(bitmap + 22) = info->infos.r2;
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	write(fd, bitmap, 54);
	create(fd, info);
}
