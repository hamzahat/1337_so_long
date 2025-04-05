/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:07 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/05 15:16:19 by hbenmoha         ###   ########.fr       */
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
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_pic, game->player_x * SIZE, game->player_y * SIZE);
		game->moves++;
		ft_putnbr(game->moves);
		ft_putchar('\n');
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
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_pic, game->player_x * SIZE, game->player_y * SIZE);
		game->moves++;
		ft_putnbr(game->moves);
		ft_putchar('\n');
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
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_pic, game->player_x * SIZE, game->player_y * SIZE);
		game->moves++;
		ft_putnbr(game->moves);
		ft_putchar('\n');
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
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_pic, game->player_x * SIZE, game->player_y * SIZE);
		game->moves++;
		ft_putnbr(game->moves);
		ft_putchar('\n');
	}
}
