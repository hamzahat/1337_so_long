/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:29:17 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/29 18:39:14 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char *av[])
{
	// t_so_long	game;

//? Initialize MiniLibX
	// game.mlx_ptr = mlx_init();
	// if (!game.mlx_ptr)
	// 	ft_safe_malloc(0,0,1);

//? parsing of input & map
	parse_map(ac, av); // todo

//? opne window
	// open_window(game.mlx_ptr, game.win_ptr);
	ft_safe_malloc(0,0,0);
	return 0;
}
