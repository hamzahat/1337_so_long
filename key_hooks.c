/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:56:38 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/05 14:36:54 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Handles key presses (movement, exit game)
#include "so_long.h"

// todo
int key_handler(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
		close_window(game);
    else if (keycode == KEY_W || keycode == KEY_up)
		player_up(game);
	else if (keycode == KEY_S || keycode == KEY_down)
		player_down(game);
	else if (keycode == KEY_A || keycode == KEY_left)
		player_left(game);
	else if (keycode == KEY_D || keycode == KEY_right)
		player_right(game);
	else
		return (1);
    return 0;
}
