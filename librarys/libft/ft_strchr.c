/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:28:39 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 21:07:24 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return (&s[count]);
		count++;
	}
	if (c == '\0')
		return (&s[count]);
	return (0);
}
