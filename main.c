/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:29:17 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/05 17:15:56 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f(){system("leaks so_long");}

int main(int ac, char *av[])
{
	// atexit(f);
	t_game	game;

//? parsing of input & map
	parse_map(ac, av, &game);

//? Initialize MiniLibX
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
	{
		ft_putstr_fd("Error\nmlx_init failed\n", 2);
		ft_safe_malloc(0, FREE_ALL, 1, NULL);
	}

//? opne window
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE, game.height * SIZE, TITLE);
	if (!game.win_ptr)
		ft_safe_malloc(0, FREE_ALL, 1, NULL);

	load_images(&game);
	draw_map(&game);

	mlx_hook(game.win_ptr, 2, 0, key_handler, &game);
	mlx_hook(game.win_ptr, ON_DESTROY, 0, close_window, &game);


	mlx_loop(game.mlx_ptr);

//? clean memory
	ft_safe_malloc(0, FREE_ALL, 0, NULL);
	return 0;
}
