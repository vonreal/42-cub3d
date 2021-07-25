/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:36:49 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 23:45:27 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		main(int argc, char **argv)
{
	t_info	info;

	init_info(&info);
	valid_arg(&info, argc, argv);
	parsing(&info);
	game(&info);
	return (0);
}
