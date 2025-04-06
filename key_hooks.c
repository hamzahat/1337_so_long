/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:56:38 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/06 23:11:12 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Handles key presses (movement, exit game)
#include "so_long.h"

int key_handler(int keycode, t_game *game)
{
    // ESC key - Close game window gracefully
    if (keycode == KEY_ESC)
        close_window(game);

    // W or UP arrow - Move player up
    else if (keycode == KEY_W || keycode == KEY_UP)
        player_up(game);

    // S or DOWN arrow - Move player down
    else if (keycode == KEY_S || keycode == KEY_DOWN)
        player_down(game);

    // A or LEFT arrow - Move player left
    else if (keycode == KEY_A || keycode == KEY_LEFT)
        player_left(game);

    // D or RIGHT arrow - Move player right
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
        player_right(game);

    // Unrecognized key - Return 1 (ignored)
    else
        return (1);

    // Key was handled - Return 0
    return (0);
}
