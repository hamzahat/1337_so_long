/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:57:10 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/06 19:40:32 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Handles window closing and memory cleanup
#include "so_long.h"

//? Destroys all images used in the game to free up memory
void	destroy_images(t_game *game)
{
//? If player image exists, destroy it
	if (game->player_pic)
		mlx_destroy_image(game->mlx_ptr, game->player_pic);
//? If collectible image exists, destroy it
	if (game->collect_pic)
		mlx_destroy_image(game->mlx_ptr, game->collect_pic);
//? If floor image exists, destroy it
	if (game->floor_pic)
		mlx_destroy_image(game->mlx_ptr, game->floor_pic);
//? If wall image exists, destroy it
	if (game->wall_pic)
		mlx_destroy_image(game->mlx_ptr, game->wall_pic);
//? If exit image exists, destroy it
	if (game->exit_pic)
		mlx_destroy_image(game->mlx_ptr, game->exit_pic);
}

//? Handles closing the window and freeing all game resources
int	close_window(t_game *game)
{
//? Destroy the game window
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
//? Destroy all game images
	destroy_images(game);
//? Free all memory allocated using ft_safe_malloc
	ft_safe_malloc(0, FREE_ALL, 0, NULL);
	return (0);
}
