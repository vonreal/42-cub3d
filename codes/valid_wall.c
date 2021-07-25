/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 23:19:28 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 20:41:19 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	check_kray1(t_info *info, int i)
{
	int	j;

	j = 1;
	while (j < (int)ft_strlen(info->map[i]))
	{
		check_content(info, i, j);
		if (!ft_strchr(info->map[i], '1'))
			error_parsing("map content of wall");
		else if (info->map[i][j] == ' ')
		{
			if ((info->map[i][j + 1] != ' ' && info->map[i][j + 1] != '1')
			|| (info->map[i][j - 1] != ' ' && info->map[i][j - 1] != '1')
			|| (info->map[i + 1][j] != ' ' && info->map[i + 1][j] != '1'))
				error_parsing("map content of wall");
		}
		j++;
	}
}

static void	check_kray2(t_info *info, int i)
{
	int	j;

	j = 1;
	while (j < (int)ft_strlen(info->map[i]))
	{
		if (!ft_strchr(info->map[i], '1'))
			error_parsing("map content of wall");
		else if (info->map[i][j] == ' ')
		{
			if ((info->map[i][j + 1] != ' ' && info->map[i][j + 1] != '1')
			|| (info->map[i][j - 1] != ' ' && info->map[i][j - 1] != '1')
			|| (info->map[i - 1][j] != ' ' && info->map[i - 1][j] != '1'))
				error_parsing("map content of wall");
		}
		j++;
	}
}

static void	check_kray3(t_info *info, int i)
{
	int	j;

	while (i < info->infos.endmap)
	{
		j = 0;
		check_content(info, i, j);
		while (info->map[i][j] != '\0')
		{
			while (info->map[i][j] == ' ')
			{
				if (info->map[i][j] == ' ')
					j++;
				else if (info->map[i][j] == '1')
					break ;
				else
					error_parsing("map content");
			}
			if (info->map[i][j] == '1')
				break ;
		}
		i++;
	}
}

static void	check_kray4(t_info *info, int i)
{
	int	j;

	while (i <= info->infos.endmap)
	{
		j = (int)ft_strlen(info->map[i]) - 1;
		check_content(info, i, j);
		while (j > 0)
		{
			while (info->map[i][j] == ' ')
				j--;
			if (info->map[i][j] == '1')
				break ;
			else
				error_parsing("map content");
			if (info->map[i][j] == '1')
				break ;
		}
		i++;
	}
}

void		valid_wall(t_info *info)
{
	check_kray1(info, 0);
	check_kray2(info, info->infos.endmap);
	check_kray3(info, 0);
	check_kray4(info, 0);
}
