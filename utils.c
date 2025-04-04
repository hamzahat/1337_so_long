/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:39:35 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/04 12:03:50 by hbenmoha         ###   ########.fr       */
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

char	*ft_strcpy(char *dst, const char *src)
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

//? Flood fill to check valide path
void	flood_fill(char **map, int x, int y , t_map size)
{
	if (x < 0 || y < 0 || x >= size.width || y >= size.height)
   	 return;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y, size);
    flood_fill(map, x - 1, y, size);
    flood_fill(map, x, y + 1, size);
    flood_fill(map, x, y - 1, size);
}

//? Function to copy a 2D array
char	**copy_map(char *zone[], t_map size)
{
	int		x;
	int		y;
	char	**arr;

	x = 0;
	y = 0;
	arr = ft_safe_malloc(sizeof(char *) * (size.height + 1), ALLOCATE, 1, NULL);
	while (y < size.height)
	{
		x = 0;
		arr[y] = ft_safe_malloc(sizeof(char) * (size.width + 1), ALLOCATE, 1, NULL);
		while (x < size.width)
		{
			arr[y][x] = zone[y][x];
			x++;
		}
		arr[y][x] = 0;
		y++;
	}
	arr[y] = NULL;
	return (arr);
}

//? Find player position
void	find_player(char **map, t_map size, t_game *count)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			if (map[i][j] == 'P')
			{
				count->player_x = j;
				count->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

//! remove this :
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	print_tab(char **tab, t_map size)
{
	int y = 0, x = 0;
	while (y < size.height)
	{
		x = 0;
		while (x < size.width)
			ft_putchar(tab[y][x++]);	
		ft_putchar('\n');
		y++;
	}
}
