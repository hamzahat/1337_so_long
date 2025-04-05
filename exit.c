/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:57:10 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/05 15:00:27 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Handles window closing and memory cleanup
#include "so_long.h"

void	destroy_images(t_game *game)
{
	if (game->player_pic)
		mlx_destroy_image(game->mlx_ptr, game->player_pic);
	if (game->collect_pic)
		mlx_destroy_image(game->mlx_ptr, game->collect_pic);
	if (game->floor_pic)
		mlx_destroy_image(game->mlx_ptr, game->floor_pic);
	if (game->wall_pic)
		mlx_destroy_image(game->mlx_ptr, game->wall_pic);
	if (game->exit_pic)
		mlx_destroy_image(game->mlx_ptr, game->exit_pic);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	destroy_images(game);
	ft_safe_malloc(0, FREE_ALL, 0, NULL);
	return (0);
}
