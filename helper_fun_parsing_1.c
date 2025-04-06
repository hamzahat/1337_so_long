/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_parsing_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:19:55 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/06 21:17:48 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//? Checks if the map file has a `.ber` extension.
void	check_map_extension(char *map_name)
{
	size_t	len;

	//* Get the length of the filename
	len = ft_strlen(map_name);

    //* Check if the filename doesn't end with ".ber"
	if (len < 4 || ft_strcmp(map_name + len - 4, ".ber") != 0)
	{
		ft_putstr_fd("Error\nMap file must have a .ber extension\n", 2);
		exit(1);
	}
}

//? Checks if the map is fully enclosed by walls ('1').
void	check_map_closed(t_game *game)
{
	int	i;

    //* Check the top and bottom borders (first and last rows)
	i = 0;
	while (i < game->width)
	{
		if ((game->map[0][i] != '1') || (game->map[game->height - 1][i] != '1'))
		{
			ft_putstr_fd("Error\nMap is not enclosed in walls.\n", 2);
			ft_safe_malloc(0, 0, ALLOCATE, NULL);
		}
		i++;
	}

    //* Check the left and right borders (first and last columns)
	i = 0;
	while (i < game->height)
	{
		if ((game->map[i][0] != '1') || (game->map[i][game->width - 1] != '1'))
		{
			ft_putstr_fd("Error\nMap is not enclosed in walls.\n", 2);
			ft_safe_malloc(0, 0, ALLOCATE, NULL);
		}
		i++;
	}
}

//? Recursively fills the map to check if all paths are valid.
void	flood_fill(char **map, int x, int y, t_game *game)
{
	//* Stop if out of bounds
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;

	//* Stop if the cell is a wall (`1`) or already filled (`F`)
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;

	//* Mark the current cell as filled (`F`)
	map[y][x] = 'F';

	//* Recursively fill adjacent cells (up, down, left, right)
	flood_fill(map, x + 1, y, game); //* Right
	flood_fill(map, x - 1, y, game); //* Left
	flood_fill(map, x, y + 1, game); //* Down
	flood_fill(map, x, y - 1, game); //* Up
}

//? Creates a copy of the map (for flood fill without modifying the original).
char	**copy_map(t_game *game)
{
	int		x;
	int		y;
	char	**arr;

	x = 0;
	y = 0;
	//* Allocate memory for rows (height + 1 for NULL)
	arr = ft_safe_malloc(sizeof(char *) * (game->height + 1), ALLOCATE, 1, NULL);
	while (y < game->height)
	{
		x = 0;
		//* Allocate memory for each row (width + 1 for NULL terminator)
		arr[y] = ft_safe_malloc(sizeof(char) * (game->width + 1), ALLOCATE, 1, NULL);
		//* Copy each cell from the original map
		while (x < game->width)
		{
			arr[y][x] = game->map[y][x];
			x++;
		}
		arr[y][x] = 0; //* Null-terminate the row
		y++;
	}
	arr[y] = NULL; //* Null-terminate the 2D array
	return (arr);
}

//? Checks if all collectibles (`C`) and the exit (`E`) are reachable after flood fill.
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
			//* If any `C` or `E` remains, they were unreachable
			if (map_cp[i][j] == 'C' || map_cp[i][j] == 'E')
			{
				ft_putstr_fd("Error\nNot all collectibles or the exit are reachable.\n", 2);
				ft_safe_malloc(0, FREE_ALL, 1, NULL); //* Clean up memory and exit
			}
			j++;
		}
		i++;
	}
}
