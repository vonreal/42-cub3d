/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:16:17 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 21:58:14 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	correct_range(int num, int min, int max)
{
	if (!(min <= num && num <= max))
		error_parsing("value range");
}

static void	valid_elements(t_elements *infos)
{
	if (infos->r1 > SCREEN_MAX_W)
		infos->r1 = SCREEN_MAX_W;
	if (infos->r2 > SCREEN_MAX_H)
		infos->r2 = SCREEN_MAX_H;
	if (infos->r1 < 0 || infos->r2 < 0)
		error_parsing("value range");
	correct_range(infos->color[0][0], 0, 255);
	correct_range(infos->color[0][1], 0, 255);
	correct_range(infos->color[0][2], 0, 255);
	correct_range(infos->color[1][0], 0, 255);
	correct_range(infos->color[1][1], 0, 255);
	correct_range(infos->color[1][2], 0, 255);
}

static void	vaild_content(t_info *info, int i, int j)
{
	if (info->map[i][j] == '0' || info->map[i][j] == '2'
		|| info->map[i][j] == 'N' || info->map[i][j] == 'S'
		|| info->map[i][j] == 'W' || info->map[i][j] == 'E')
	{
		if (info->map[i + 1][j] == ' ' || info->map[i - 1][j] == ' ' ||
			info->map[i][j + 1] == ' ' || info->map[i][j - 1] == ' ')
			error_parsing("map content");
	}
	else if (info->map[i][j] == ' ')
	{
		if ((info->map[i][j + 1] != ' ' && info->map[i][j + 1] != '1')
		|| (info->map[i][j - 1] != ' ' && info->map[i][j - 1] != '1')
		|| (info->map[i + 1][j] != ' ' && info->map[i + 1][j] != '1')
		|| (info->map[i - 1][j] != ' ' && info->map[i - 1][j] != '1'))
			error_parsing("map content");
	}
	else if (info->map[i][j] == '1')
		return ;
	else if (info->map[i][j] < 32)
		return ;
	else
		error_parsing("map content");
}

static void	valid_map(t_info *info)
{
	int		i;
	int		j;
	int		col;
	int		row;

	i = 0;
	col = ft_strlen(info->map[i]);
	row = info->infos.endmap - 1;
	valid_wall(info);
	j = 1;
	while (j < row - 1)
	{
		i = 1;
		while (i < col - 1)
		{
			vaild_content(info, j, i);
			i++;
		}
		j++;
	}
}

void		parsing(t_info *info)
{
	parsing_elements(info);
	valid_elements(&info->infos);
	if (info->infos.err < 0)
		error_parsing(0);
	parsing_map(info);
	if (info->infos.err < 0)
		error_parsing(0);
	valid_map(info);
}
