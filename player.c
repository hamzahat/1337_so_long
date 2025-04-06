/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:07 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/07 00:21:13 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Handles player movement & interactions
#include "so_long.h"

//? Move player up if valid
void	player_up(t_game *game)
{
	if (game->player_y > 1 && game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';          // Clear old position
		game->map[game->player_y - 1][game->player_x] = 'P';      // Set new position

        // Update graphics
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_pic, game->player_x * SIZE, game->player_y * SIZE);
		find_player(game);                                        // Update player coordinates
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_pic, game->exit_x * SIZE, game->exit_y * SIZE);  // Redraw exit
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_pic, game->player_x * SIZE, game->player_y * SIZE);
		game->moves++;                                            // Increment move counter
		ft_putstr_fd("Moves = ", 1);
		ft_putnbr(game->moves);
		ft_putchar('\n');
		update_map_info(game);                                    // Update game state
		if (game->player_x == game->exit_x && game->player_y == game->exit_y && game->coins == 0)
			close_window(game);                                   // Win condition check
	}
}

//? Move player down if valid
void	player_down(t_game *game)
{
	if (game->player_y < game->height - 1 && game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y + 1][game->player_x] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_pic, game->player_x * SIZE, game->player_y * SIZE);
		find_player(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_pic, game->exit_x * SIZE, game->exit_y * SIZE);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_pic, game->player_x * SIZE, game->player_y * SIZE);
		game->moves++;
		ft_putstr_fd("Moves = ", 1);
		ft_putnbr(game->moves);
		ft_putchar('\n');
		update_map_info(game);
		if (game->player_x == game->exit_x && game->player_y == game->exit_y && game->coins == 0)
			close_window(game);
	}
}

//? Move player left if valid
void	player_left(t_game *game)
{
	if (game->player_x > 1 && game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x - 1] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_pic, game->player_x * SIZE, game->player_y * SIZE);
		find_player(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_pic, game->exit_x * SIZE, game->exit_y * SIZE);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_pic, game->player_x * SIZE, game->player_y * SIZE);
		game->moves++;
		ft_putstr_fd("Moves = ", 1);
		ft_putnbr(game->moves);
		ft_putchar('\n');
		update_map_info(game);
		if (game->player_x == game->exit_x && game->player_y == game->exit_y && game->coins == 0)
			close_window(game);
	}
}

//? Move player right if valid
void	player_right(t_game *game)
{
	if (game->player_x < game->width - 1 && game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x + 1] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_pic, game->player_x * SIZE, game->player_y * SIZE);
		find_player(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_pic, game->exit_x * SIZE, game->exit_y * SIZE);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_pic, game->player_x * SIZE, game->player_y * SIZE);
		game->moves++;
		ft_putstr_fd("Moves = ", 1);
		ft_putnbr(game->moves);
		ft_putchar('\n');
		update_map_info(game);
		if (game->player_x == game->exit_x && game->player_y == game->exit_y && game->coins == 0)
			close_window(game);
	}
}
