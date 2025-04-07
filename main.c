/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:29:17 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/07 00:56:03 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void f(){system("leaks so_long");} // ? to test memory leaks
// void f(){system("lsof -c so_long");} //? to test if any file descriptor is opend 

int main(int ac, char *av[])
{
	// atexit(f);
	t_game	game;                   // Main game structure

//? Parse command line arguments and map file
	parse_map(ac, av, &game);

//? Initialize MiniLibX graphics system
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)              // Check if initialization failed
	{
		ft_putstr_fd("Error\nmlx_init failed\n", 2);
		ft_safe_malloc(0, FREE_ALL, 1, NULL);
	}

//? Create game window
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE, game.height * SIZE, TITLE);
	if (!game.win_ptr)
		ft_safe_malloc(0, FREE_ALL, 1, NULL);

//? Load game textures and render initial map
	load_images(&game);
	draw_map(&game);

//? Set up event hooks
	mlx_hook(game.win_ptr, 2, 0, key_handler, &game);        // Key press events
	mlx_hook(game.win_ptr, ON_DESTROY, 0, close_window, &game); // Window close event


//? Start main game loop
	mlx_loop(game.mlx_ptr);

//? clean up memory
	ft_safe_malloc(0, FREE_ALL, 0, NULL);
	return 0;
}
