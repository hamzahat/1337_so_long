/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:49:43 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/05 13:12:28 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Loads & renders images (player, walls, collectibles, etc.)
#include "so_long.h"

void load_images(t_game *game)
{
    int width;
    int height;

    game->wall_pic = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &width, &height);
    game->floor_pic = mlx_xpm_file_to_image(game->mlx_ptr, "textures/floor.xpm", &width, &height);
    game->player_pic = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player.xpm", &width, &height);
    game->collect_pic = mlx_xpm_file_to_image(game->mlx_ptr, "textures/collect.xpm", &width, &height);
    game->exit_pic = mlx_xpm_file_to_image(game->mlx_ptr, "textures/exit.xpm", &width, &height);
}

void draw_map(t_game *game)
{
    int		x;
	int		y;
	char	tile;
	void	*img;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_pic, x * SIZE, y * SIZE);
            tile = game->map[y][x];
            img = NULL;
            if (tile == '1')
                img = game->wall_pic;
            else if (tile == 'P')
                img = game->player_pic;
            else if (tile == 'C')
                img = game->collect_pic;
            else if (tile == 'E')
                img = game->exit_pic;
            if (img)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x * SIZE, y * SIZE);
            x++;
        }
        y++;
    }
}
