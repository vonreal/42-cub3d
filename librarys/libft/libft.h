/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:57:21 by jna               #+#    #+#             */
/*   Updated: 2021/05/24 21:44:54 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_atoi(char *str);
void	*ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strs_len(char **strs);
int		ft_isdigit(int c);

#endif
