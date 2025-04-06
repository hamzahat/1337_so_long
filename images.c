/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:49:43 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/06 23:07:00 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Loads & renders images (player, walls, collectibles, etc.)
#include "so_long.h"

//? Loads XPM image files into the game for rendering.
void    load_images(t_game *game)
{
    int width;   // Will store image width (unused here)
    int height;  // Will store image height (unused here)

    // Load wall texture
    game->wall_pic = mlx_xpm_file_to_image(
        game->mlx_ptr,         // MLX graphics instance
        "textures/wall.xpm",   // Path to wall image
        &width, &height        // Image dimensions (optional)
    );

    // Load floor texture
    game->floor_pic = mlx_xpm_file_to_image(
        game->mlx_ptr, "textures/floor.xpm", &width, &height
    );

    // Load player texture
    game->player_pic = mlx_xpm_file_to_image(
        game->mlx_ptr, "textures/player.xpm", &width, &height
    );

    // Load collectible (coin) texture
    game->collect_pic = mlx_xpm_file_to_image(
        game->mlx_ptr, "textures/collect.xpm", &width, &height
    );

    // Load exit texture
    game->exit_pic = mlx_xpm_file_to_image(
        game->mlx_ptr, "textures/exit.xpm", &width, &height
    );
}

//? Returns the corresponding image pointer for a given tile character.
static void	*get_tile_img(t_game *game, char tile)
{
	if (tile == '1')       // Wall
		return (game->wall_pic);
	else if (tile == 'P')  // Player
		return (game->player_pic);
	else if (tile == 'C')  // Collectible (coin)
		return (game->collect_pic);
	else if (tile == 'E')  // Exit
		return (game->exit_pic);
	return (NULL);         // Default (floor or invalid)
}

//? Renders the entire map by drawing each tile.
void	draw_map(t_game *game)
{
	int		x;           // Tile coordinates (columns and rows)
	int		y;           // Current tile character (e.g., '1', 'P')
	char	tile;        // Image pointer to render
	void	*img;

	y = 0;
    while (y < game->height)  // Loop through each row
    {
        x = 0;
        while (x < game->width)  // Loop through each column
        {
            // Draw floor first (background for all tiles)
            mlx_put_image_to_window(
                game->mlx_ptr,       // MLX graphics instance
                game->win_ptr,       // MLX window pointer
                game->floor_pic,     // Floor image
                x * SIZE, y * SIZE   // Scaled pixel position
            );

            // Get current tile and its corresponding image
            tile = game->map[y][x];
            img = get_tile_img(game, tile);

            // Overlay the tile image if it exists
            if (img)
                mlx_put_image_to_window(
                    game->mlx_ptr, game->win_ptr,
                    img,            // Wall/Player/Coin/Exit image
                    x * SIZE, y * SIZE
                );
            x++;
        }
        y++;
    }
}
