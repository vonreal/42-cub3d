/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:34:58 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 21:06:13 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_str(char str)
{
	if (str == '\t' || str == '\n'
					|| str == '\v'
					|| str == '\f'
					|| str == '\r'
					|| str == ' ')
		return (0);
	return (1);
}

int			ft_atoi(char *str)
{
	int count;
	int sign;
	int num;

	count = 0;
	sign = 1;
	num = 0;
	while (!(check_str(str[count])))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
		num = (num * 10) + str[count++] - '0';
	return ((int)(num * sign));
}
