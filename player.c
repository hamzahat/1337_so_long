/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:07 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/05 18:17:51 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Handles player movement & interactions
#include "so_long.h"

void	player_up(t_game *game)
{
	if (game->player_y > 1 && game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
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
