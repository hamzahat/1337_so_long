/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza_hat <hamza_hat@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:39:35 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/31 12:32:03 by hamza_hat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_map_check(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
		i--;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

char *ft_strcpy(char *dst, const char *src)
{
	int i = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
//todo: fix this shit

// static void	flood_fill_recur(char **tab, t_point size, int x , int y, char target)
// {
// 	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
// 		return;
// 	if (tab[y][x] != target)
// 		return;
// 	tab[y][x] = 'F';
// 	flood_fill_recur(tab, size, x + 1, y, target);
// 	flood_fill_recur(tab, size, x - 1, y, target);
// 	flood_fill_recur(tab, size, x, y + 1, target);
// 	flood_fill_recur(tab, size, x, y - 1, target);
// }

// void	flood_fill(char *tab[], t_point size, t_point begin)
// {
// 	char target = tab[begin.x][begin.y];

// 	if (target == 'F') //* if it's already 'F' , no need to fill
// 		return;
// 	flood_fill_recur(tab, size, begin.x, begin.y, target);
// }
