/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:29:17 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/04 23:58:04 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char *av[])
{
	t_game	game;

//? Initialize MiniLibX
	// game.mlx_ptr = mlx_init();
	// if (!game.mlx_ptr)
	// 	ft_safe_malloc(0, FREE_ALL, 1, NULL);

//? parsing of input & map
	parse_map(ac, av, &game);

//? opne window
	// game.win_ptr = mlx_new_window(game.mlx_ptr, WIDTH, HEIGHT, "so_long");
	// if (!game.win_ptr)
	// 	ft_safe_malloc(0, FREE_ALL, 1, NULL);
	// mlx_hook(game.win_ptr, 2, 0, key_handler, game.mlx_ptr);
	// mlx_hook(game.win_ptr, 17, 0, close_window, game.mlx_ptr);


	// mlx_loop(game.mlx_ptr);
//? clean memory
	ft_safe_malloc(0, FREE_ALL, 0, NULL);
	return 0;
}
