/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:42:21 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/06 20:16:37 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//? Initialize all fields in the game struct to default values (mostly 0 or NULL)
void	game_init(t_game *game)
{
	game->coins = 0;        //* No coins collected at start
	game->exit = 0;         //* Exit count initialized
	game->height = 0;       //* Map height not known yet
	game->map = NULL;       //* Map pointer is null until loaded
	game->mlx_ptr = NULL;   //* MLX (graphics library) pointer not initialized yet
	game->player = 0;       //* Player count is 0 until parsed
	game->player_x = 0;     //* Player's X position (to be found later)
	game->player_y = 0;     //* Player's Y position (to be found later)
	game->width = 0;        //* Map width not known yet
	game->win_ptr = NULL;   //* Window pointer not initialized yet
	game->moves = 0;        //* Player hasn't moved yet
}

//? Count number of coins, exits, and players on the map and store in struct
void	update_map_info(t_game *map_inf)
{
	int	i;
	int	j;

	i = 0;
	map_inf->coins = 0;    //* Reset coin count
	map_inf->exit = 0;     //* Reset exit count
	map_inf->player = 0;   //* Reset player count

	find_player(map_inf);  //* Get player position (sets player_x/y)
	find_exit(map_inf);    //* Get exit position (sets exit_x/y)

	//* Loop through each tile in the map
	while (i < map_inf->height)
	{
		j = 0;
		while (j < map_inf->width)
		{
			if (map_inf->map[i][j] == 'C')       //* Found a coin
				map_inf->coins++;
			else if (map_inf->map[i][j] == 'E')  //* Found an exit
				map_inf->exit++;
			else if (map_inf->map[i][j] == 'P')  //* Found a player
				map_inf->player++;
			j++;
		}
		i++;
	}
}

//? Find exit ( E ) in the map and store its position
void	find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E') //* Found an exit
			{
				game->exit_x = j;  //* Save X coordinate of exit
				game->exit_y = i;  //* Save Y coordinate of exit
				return ;           //* Stop after first found
			}
			j++;
		}
		i++;
	}
}

//? Find the player (P) in the map and store its position
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
			if (game->map[i][j] == 'P') //* Found a player
			{
				game->player_x = j;  //* Save X coordinate of player
				game->player_y = i;  //* Save Y coordinate of player
				return ;             //* Stop after first found
			}
			j++;
		}
		i++;
	}
}
