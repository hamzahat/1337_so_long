/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:57:10 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/03/28 21:31:32 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Handles window closing and memory cleanup
#include "so_long.h"

int	close_window(void *mlx, void *win)
{
	(void)mlx;
	(void)win;
	printf("mlx %s win %s\n", mlx, win);
	// mlx_destroy_window(mlx, win);
	// ft_safe_malloc(0,0,1);
	exit(-1);
}