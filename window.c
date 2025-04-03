/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:48:31 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/03 18:56:32 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Creates and manages the game window
#include "so_long.h"

void	open_window(void *mlx, void *win)
{
	//? Create a window
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "so_long");
	if (!win)
		ft_safe_malloc(0,0,1,0);
	mlx_hook(win, 17, 0, close_window, mlx);
	//? Keep the window open
	mlx_loop(mlx);
}
