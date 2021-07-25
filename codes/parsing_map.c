/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:45:44 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 22:54:57 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	get_line_count(t_info *info)
{
	int		fd;
	char	*line;
	int		count;

	if ((fd = open(info->infos.map, O_RDONLY)) < 0)
		error_parsing(0);
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

static void	set_map(t_info *info, int j)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if ((fd = open(info->infos.map, O_RDONLY)) < 0)
		error_parsing("file open");
	while (i < info->infos.begmap)
	{
		get_next_line(fd, &line);
		free(line);
		i++;
	}
	i = 0;
	info->infos.endmap = j - info->infos.begmap;
	while (i <= info->infos.endmap)
	{
		get_next_line(fd, &info->map[i]);
		i++;
	}
	info->map[i] = 0;
	info->ray.dist = 0;
}

void		parsing_map(t_info *info)
{
	int		count;

	count = get_line_count(info);
	if (!(info->map = (char **)malloc((sizeof(char *) * \
			(count - info->infos.begmap + 2)))))
		error_parsing("map");
	set_map(info, count);
}

void		check_content(t_info *info, int i, int j)
{
	if (info->map[i][j] == '0' || info->map[i][j] == '2'
		|| info->map[i][j] == 'N' || info->map[i][j] == 'S'
		|| info->map[i][j] == 'W' || info->map[i][j] == 'E')
		error_parsing("map content");
}
