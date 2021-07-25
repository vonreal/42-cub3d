/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:43:18 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 18:40:37 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	parsing_path(char *line, t_info *info, int idx)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	temp = ft_split(line, ' ');
	if (ft_strs_len(temp) != 2)
		error_parsing(0);
	while (temp[i] != NULL)
	{
		free(temp[i]);
		info->infos.path[idx] = temp[++i];
		info->infos.begmap++;
		break ;
	}
	free(temp);
}
