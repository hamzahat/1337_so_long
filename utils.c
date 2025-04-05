/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:39:35 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/05 00:01:53 by hbenmoha         ###   ########.fr       */
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
void	flood_fill(char **map, int x, int y , t_game *game)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
   	 return;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y, game);
    flood_fill(map, x - 1, y, game);
    flood_fill(map, x, y + 1, game);
    flood_fill(map, x, y - 1, game);
}

//? Function to copy a 2D array
char	**copy_map(t_game *game)
{
	int		x;
	int		y;
	char	**arr;

	x = 0;
	y = 0;
	arr = ft_safe_malloc(sizeof(char *) * (game->height + 1), ALLOCATE, 1, NULL);
	while (y < game->height)
	{
		x = 0;
		arr[y] = ft_safe_malloc(sizeof(char) * (game->width + 1), ALLOCATE, 1, NULL);
		while (x < game->width)
		{
			arr[y][x] = game->map[y][x];
			x++;
		}
		arr[y][x] = 0;
		y++;
	}
	arr[y] = NULL;
	return (arr);
}

//? Find player position
void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

//? initialize all the game struct to 0
void	game_init(t_game *game)
{
	game->coins = 0;
	game->exit = 0;
	game->height = 0;
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->width = 0;
	game->win_ptr = NULL;
}

//? print all the game struct elements
void	print_struct(t_game *game)
{
	printf("coins = %d\n", game->coins);
	printf("exit = %d\n", game->exit);
	printf("height = %d\n", game->height);
	printf("map = %p\n", game->map);
	printf("mlx ptr = %p\n", game->mlx_ptr);
	printf("player = %d\n", game->player);
	printf("player x = %d\n", game->player_x);
	printf("player_y = %d\n", game->player_y);
	printf("player width = %d\n", game->width);
	printf("win_ptr = %p", game->win_ptr);
}

void	update_map_info(t_game *map_inf)
{
	int	i;
	int	j;

	i = 0;
	map_inf->coins = 0;
	map_inf->exit = 0;
	map_inf->player = 0;
	find_player(map_inf);
	while (i < map_inf->height)
	{
		j = 0;
		while (j < map_inf->width)
		{
			if (map_inf->map[i][j] == 'C')
				map_inf->coins++;
			else if (map_inf->map[i][j] == 'E')
				map_inf->exit++;
			else if (map_inf->map[i][j] == 'P')
				map_inf->player++;
			j++;
		}
		i++;
	}
}

void	is_valid(t_game *game, char **map_cp)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map_cp[i][j] == 'C' || map_cp[i][j] == 'E')
			{
				ft_putstr_fd("Error: Not all collectibles or the exit are reachable.\n", 2);
				ft_safe_malloc(0, FREE_ALL, 1, NULL);
			}
			j++;
		}
		i++;
	}
}

//! remove this : ( print tab )
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	print_tab(t_game *game)
{
	int y = 0, x = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			ft_putchar(game->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
