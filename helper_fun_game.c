/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:42:21 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/06 19:53:55 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->moves = 0;
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
	find_exit(map_inf);
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

//? Find exit ( E ) position
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
			if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

//? Find player ( P ) position
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

