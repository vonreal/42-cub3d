/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:57:11 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 23:14:43 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	error_arg(void)
{
	printf("[ERROR]: argument.\n");
	exit(0);
}

static int	is_format(char *target, char *format)
{
	int		size;
	int		i;

	size = ft_strlen(target) - 1;
	i = ft_strlen(format) - 1;
	while (i >= 0)
	{
		if (target[size] == format[i])
		{
			size--;
			i--;
		}
		else
			error_arg();
	}
	return (1);
}

static int	is_equal(char *dst, char *src)
{
	int		i;

	if (ft_strlen(dst) == ft_strlen(src))
	{
		i = 0;
		while (i < (int)ft_strlen(dst))
		{
			if (dst[i] != src[i])
				error_arg();
			i++;
		}
	}
	else
		error_arg();
	return (1);
}

void		valid_arg(t_info *info, int argc, char **argv)
{
	int		size;

	if (2 <= argc && argc <= 3)
	{
		size = ft_strlen(argv[1]);
		if (size < 5)
			error_arg();
		if (is_format(argv[1], ".cub"))
			info->infos.map = argv[1];
		if (argv[2])
		{
			if (is_equal(argv[2], "--save"))
				info->infos.flag = 1;
		}
	}
	else
	{
		error_arg();
		return ;
	}
}
