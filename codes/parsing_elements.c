/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:27:14 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 22:17:42 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	parsing_render(char *line, t_info *info)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(line, ' ');
	if ((ft_strs_len(temp) != 3) || info->infos.r1 != -1)
		error_parsing("render count");
	while (temp[i] != NULL)
	{
		if (!(is_numbers(temp[1]) && is_numbers(temp[2])))
			error_parsing("render only num");
		if (ft_strchr(temp[i], 'R'))
		{
			free(temp[i]);
			info->infos.r1 = ft_atoi(temp[++i]);
			free(temp[i]);
			info->infos.r2 = ft_atoi(temp[++i]);
			free(temp[i]);
			info->infos.begmap++;
			break ;
		}
		free(temp[i]);
		break ;
	}
	free(temp);
}

static void	parsing_path(char *line, t_info *info, int idx)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	temp = ft_split(line, ' ');
	if (ft_strs_len(temp) != 2 || info->infos.path[idx] != NULL)
		error_parsing("path count");
	while (temp[i])
	{
		free(temp[i]);
		info->infos.path[idx] = temp[++i];
		info->infos.begmap++;
		break ;
	}
	free(temp);
}

static void	parsing_color(char *line, t_elements *infos, int idx)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(line, ',');
	if (ft_strs_len(temp) != 3)
		error_parsing("color");
	while (temp[i] != NULL)
	{
		if (!(is_numbers(temp[0]) && is_numbers(temp[1]) && \
								is_numbers(temp[2])))
			error_parsing("color");
		infos->color[idx][0] = ft_atoi(temp[i]);
		free(temp[i++]);
		infos->color[idx][1] = ft_atoi(temp[i]);
		free(temp[i++]);
		infos->color[idx][2] = ft_atoi(temp[i]);
		free(temp[i]);
		infos->begmap++;
		break ;
	}
	free(temp);
}

static void	parsing_element(t_info *info, char *line)
{
	if (info->infos.err < 0)
		error_parsing("parsing element");
	if (ft_strncmp(line, "R ", 2) == 0)
		parsing_render(line, info);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		parsing_path(line, info, NORTH);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parsing_path(line, info, SOUTH);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parsing_path(line, info, EAST);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parsing_path(line, info, WEST);
	else if (ft_strncmp(line, "S ", 2) == 0)
		parsing_path(line, info, SPRITE);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parsing_color(line + 2, &info->infos, FLOOR);
	else if (ft_strncmp(line, "C ", 2) == 0)
		parsing_color(line + 2, &info->infos, CEILLING);
	else if (ft_strlen(line) == 0)
		info->infos.begmap++;
}

void		parsing_elements(t_info *info)
{
	int		fd;
	char	*line;

	if ((fd = open(info->infos.map, O_RDONLY)) < 0)
		error_parsing("file status");
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) > 0)
			parsing_element(info, line);
		free(line);
	}
	if (ft_strlen(line) == 0)
		info->infos.begmap++;
	free(line);
	if (get_next_line(fd, &line) < 0)
		info->infos.err = -1;
	free(line);
	close(fd);
}
